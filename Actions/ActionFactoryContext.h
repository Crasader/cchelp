//
//  ActionFactoryContext.h
//  GodRage-Endless-Revamp
//
//  Created by Vinova on 5/22/15.
//
//

#pragma once
#include "Def.h"
#include "vsson.h"
#include "hmap.h"
#include "jsonserialization.h"

namespace ccHelp {
    typedef std::function<void()> CallFuncFunction;
    typedef std::function<void(cocos2d::Node*)> CallFuncNFunction;
    
    class ActionContext
    {
    private:
        class BaseHolder
        {
        public:
            virtual ~BaseHolder();
            
            virtual BaseHolder* clone() const = 0;
        };
        
        template <typename T>
        class Holder : public BaseHolder
        {
        private:
            T data;
            
        public:
            Holder(const T &t)
            : data(t) {}
            ~Holder() {}
            
            const T& get() const
            {
                return data;
            }
            
            T& get()
            {
                return data;
            }
            
            Holder<T>* clone() const override
            {
                return new Holder<T>(data);
            }
        };
        
        hmap<std::string, BaseHolder *> mData;
        
    public:
        ActionContext() = default;
        ActionContext(const ActionContext &ctx);
        ActionContext& operator=(const ActionContext &ctx);
        ActionContext(ActionContext &&ctx);
        ~ActionContext();
        
        template <typename T>
        bool get(const std::string &k, T &t) const
        {
            auto it = mData.find(k);
            if (it == mData.cend() ||
                it->second == nullptr)
                return false;
            
            auto *holder = dynamic_cast<Holder<T>*>(it->second);
            if (!holder)
                return false;
            
            t = holder->get();
            return true;
        }
        
        template <typename T>
        ActionContext& put(const std::string &k, const T& data)
        {
            auto it = mData.find(k);
            if (it != mData.end())
            {
                delete it->second;
                mData.erase(it);
            }
            
            Holder<T> *holder = new Holder<T>(data);
            mData[k] = holder;
            
            return *this;
        }
        
        template <typename T>
        ActionContext& operator()(const std::string &k, const T& data);
    };
    
#define ACTION_CONTEXT_IMPLICIT(TYPE) \
    template<> \
    inline ActionContext& ActionContext::operator()(const std::string &k, const TYPE &data) \
    { \
        return this->put(k, data); \
    }
    
    ACTION_CONTEXT_IMPLICIT(int);
    ACTION_CONTEXT_IMPLICIT(float);
    ACTION_CONTEXT_IMPLICIT(cocos2d::Size);
    ACTION_CONTEXT_IMPLICIT(cocos2d::Vec2);
    ACTION_CONTEXT_IMPLICIT(CallFuncFunction);
    ACTION_CONTEXT_IMPLICIT(CallFuncNFunction);
    
    class AFContext
    {
    private:
        const Json::Value mJs;
        const ActionContext &ctx;
        const Json::Value &js;
        
    public:
        AFContext(const ActionContext &ctx, const Json::Value &js);
        AFContext(const ActionContext &ctx, const vsson::VSSObject &vss);
        
        AFContext(const AFContext&) = default;
        AFContext& operator=(const AFContext&) = default;
        
        template <typename T>
        bool getField(const std::string &k, T &t) const
        {
            if (js.isMember(k))
            {
                if (isReference(k))
                {
                    std::string ref = js[k].asString();
                    ref = ref.substr(1, ref.length() - 1);
                    
                    return ctx.get<T>(k, t);
                }
                
                return Json::type::deserialize(js[k], t);
            }
            
            return false;
        }
        
        bool hasField(const std::string &k) const
        {
            return js.isMember(k);
        }
        
        bool isReference(const std::string &k) const
        {
            return js[k].isString() && js[k].asString()[0] == '@';
        }
        
        const ActionContext& getContext() const
        {
            return ctx;
        }
    };
}
