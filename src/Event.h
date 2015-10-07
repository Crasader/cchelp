#pragma once
#include <hash_container/hmap.h>
#include <list>
#include <functional>

namespace ccHelp
{
    template<typename T1 = void, typename T2 = void, typename T3 = void, typename T4 = void, typename T5 = void>
    struct Event;
    
    template<>
    struct Event<void()>
    {
        hmap<std::string, std::function<void()>*> namedFuncs;
        std::list<std::function<void()>> funcs;
        
        Event<void()>() {}
        
        Event<void()>& operator-=(std::function<void()> f)
        {
            auto ite = funcs.begin();
            while (ite != funcs.end())
            {
                if (ite->target_type() == f.target_type() &&
                    ite->target<void(*)()>() == f.target<void(*)()>())
                {
                    break;
                }
                
                ++ite;
            }
            
            if (ite != funcs.end())
            {
                funcs.erase(ite);
            }
            
            return *this;
        }
        
        Event<void()>& operator+=(std::function<void()> f)
        {
            this->funcs.push_back(f);
            return *this;
        }
        
        Event<void()>& operator+=(Event<void()> &sf)
        {
            for (auto &f : sf.funcs)
            {
                this->funcs.push_back(f);
            }
            
            return *this;
        }
        
        void clear()
        {
            funcs.clear();
            namedFuncs.clear();
        }
        
        operator bool()
        {
            for (auto &f : this->funcs)
            {
                if (f)
                    return true;
            }
            
            return false;
        }
        
        void operator()()
        {
            std::list<std::function<void()>> _copy(funcs);
            for (auto &f : _copy)
            {
                if (f)
                    f();
            }
        }
        
        void add(std::function<void()> f, const std::string &name)
        {
            assert(namedFuncs.find(name) == namedFuncs.end());
            
            funcs.push_back(f);
            namedFuncs[name] = &(funcs.back());
        }
        
    private:
        // Not allowed to copy
        Event<void()>(const Event<void()> &e) {}
        Event<void()>& operator=(const Event<void()> &e) {return *this;}
    };
    
    template<typename T1>
    struct Event<void(T1)>
    {
        std::list<std::function<void(T1)>> funcs;
        
        Event<void(T1)>() {}
        
        Event<void(T1)>& operator-=(std::function<void(T1)> f)
        {
            auto ite = funcs.begin();
            while (ite != funcs.end())
            {
                if (ite->target_type() == f.target_type() &&
                    ite->template target<void(*)(T1)>() == f.template target<void(*)(T1)>())
                {
                    break;
                }
                
                ++ite;
            }
            
            if (ite != funcs.end())
            {
                funcs.erase(ite);
            }
            
            return *this;
        }
        
        Event<void(T1)>& operator+=(std::function<void(T1)> f)
        {
            this->funcs.push_back(f);
            return *this;
        }
        
        Event<void(T1)>& operator+=(Event<void(T1)> &sf)
        {
            for (auto &f : sf.funcs)
            {
                this->funcs.push_back(f);
            }
            
            return *this;
        }
        
        void clear()
        {
            funcs.clear();
        }
        
        operator bool()
        {
            for (auto &f : this->funcs)
            {
                if (f)
                    return true;
            }
            
            return false;
        }
        
        void operator()(T1 p1)
        {
            std::list<std::function<void(T1)>> _copy(funcs);
            for (auto &f : _copy)
            {
                if (f)
                    f(p1);
            }
        }
        
    private:
        // Not allowed to copy
        Event<void(T1)>(const Event<void(T1)> &e) {}
        Event<void(T1)>& operator=(const Event<void(T1)> &e) {return *this;}
    };
    
    template<typename T1, typename T2>
    struct Event<void(T1, T2)>
    {
        std::list<std::function<void(T1, T2)>> funcs;
        
        Event<void(T1, T2)>() {}
        
        Event<void(T1, T2)>& operator-=(std::function<void(T1, T2)> f)
        {
            auto ite = funcs.begin();
            while (ite != funcs.end())
            {
                if (ite->target_type() == f.target_type() &&
                    ite->template target<void(*)(T1, T2)>() == f.template target<void(*)(T1, T2)>())
                {
                    break;
                }
                
                ++ite;
            }
            
            if (ite != funcs.end())
            {
                funcs.erase(ite);
            }
            
            return *this;
        }
        
        Event<void(T1, T2)>& operator+=(std::function<void(T1, T2)> f)
        {
            this->funcs.push_back(f);
            return *this;
        }
        
        Event<void(T1, T2)>& operator+=(Event<void(T1, T2)> &sf)
        {
            for (auto &f : sf.funcs)
            {
                this->funcs.push_back(f);
            }
            
            return *this;
        }
        
        void clear()
        {
            funcs.clear();
        }
        
        operator bool()
        {
            for (auto &f : this->funcs)
            {
                if (f)
                    return true;
            }
            
            return false;
        }
        
        void operator()(T1 p1, T2 p2)
        {
            std::list<std::function<void(T1, T2)>> _copy(funcs);
            for (auto &f : _copy)
            {
                if (f)
                    f(p1, p2);
            }
        }
        
    private:
        // Not allowed to copy
        Event<void(T1, T2)>(const Event<void(T1, T2)> &e) {}
        Event<void(T1, T2)>& operator=(const Event<void(T1, T2)> &e) {return *this;}
    };
    
    template<typename T1, typename T2, typename T3>
    struct Event<void(T1, T2, T3)>
    {
        std::list<std::function<void(T1, T2, T3)>> funcs;
        
        Event<void(T1, T2, T3)>() {}
        
        Event<void(T1, T2, T3)>& operator-=(std::function<void(T1, T2, T3)> f)
        {
            auto ite = funcs.begin();
            while (ite != funcs.end())
            {
                if (ite->target_type() == f.target_type() &&
                    ite->template target<void(*)(T1, T2, T3)>() == f.template target<void(*)(T1, T2, T3)>())
                {
                    break;
                }
                
                ++ite;
            }
            
            if (ite != funcs.end())
            {
                funcs.erase(ite);
            }
            
            return *this;
        }
        
        Event<void(T1, T2, T3)>& operator+=(std::function<void(T1, T2, T3)> f)
        {
            this->funcs.push_back(f);
            return *this;
        }
        
        Event<void(T1, T2, T3)>& operator+=(Event<void(T1, T2, T3)> &sf)
        {
            for (auto &f : sf.funcs)
            {
                this->funcs.push_back(f);
            }
            
            return *this;
        }
        
        void clear()
        {
            funcs.clear();
        }
        
        operator bool()
        {
            for (auto &f : this->funcs)
            {
                if (f)
                    return true;
            }
            
            return false;
        }
        
        void operator()(T1 p1, T2 p2, T3 p3)
        {
            std::list<std::function<void(T1, T2, T3)>> _copy(funcs);
            for (auto &f : _copy)
            {
                if (f)
                    f(p1, p2, p3);
            }
        }
        
    private:
        // Not allowed to copy
        Event<void(T1, T2, T3)>(const Event<void(T1, T2, T3)> &e) {}
        Event<void(T1, T2, T3)>& operator=(const Event<void(T1, T2, T3)> &e) {return *this;}
    };
    
    template<typename T1, typename T2, typename T3, typename T4>
    struct Event<void(T1, T2, T3, T4)>
    {
        std::list<std::function<void(T1, T2, T3, T4)>> funcs;
        
        Event<void(T1, T2, T3, T4)>() {}
        
        Event<void(T1, T2, T3, T4)>& operator-=(std::function<void(T1, T2, T3, T4)> f)
        {
            auto ite = funcs.begin();
            while (ite != funcs.end())
            {
                if (ite->target_type() == f.target_type() &&
                    ite->template target<void(*)(T1, T2, T3, T4)>() == f.template target<void(*)(T1, T2, T3, T4)>())
                {
                    break;
                }
                
                ++ite;
            }
            
            if (ite != funcs.end())
            {
                funcs.erase(ite);
            }
            
            return *this;
        }
        
        Event<void(T1, T2, T3, T4)>& operator+=(std::function<void(T1, T2, T3, T4)> f)
        {
            this->funcs.push_back(f);
            return *this;
        }
        
        Event<void(T1, T2, T3, T4)>& operator+=(Event<void(T1, T2, T3, T4)> &sf)
        {
            for (auto &f : sf.funcs)
            {
                this->funcs.push_back(f);
            }
            
            return *this;
        }
        
        void clear()
        {
            funcs.clear();
        }
        
        operator bool()
        {
            for (auto &f : this->funcs)
            {
                if (f)
                    return true;
            }
            
            return false;
        }
        
        void operator()(T1 p1, T2 p2, T3 p3, T4 p4)
        {
            std::list<std::function<void(T1, T2, T3, T4)>> _copy(funcs);
            for (auto &f : _copy)
            {
                if (f)
                    f(p1, p2, p3, p4);
            }
        }
        
    private:
        // Not allowed to copy
        Event<void(T1, T2, T3, T4)>(const Event<void(T1, T2, T3, T4)> &e) {}
        Event<void(T1, T2, T3, T4)>& operator=(const Event<void(T1, T2, T3, T4)> &e) {return *this;}
    };
    
    template<typename T1, typename T2, typename T3, typename T4, typename T5>
    struct Event<void(T1, T2, T3, T4, T5)>
    {
        std::list<std::function<void(T1, T2, T3, T4, T5)>> funcs;
        
        Event<void(T1, T2, T3, T4, T5)>() {}
        
        Event<void(T1, T2, T3, T4, T5)>& operator-=(std::function<void(T1, T2, T3, T4, T5)> f)
        {
            auto ite = funcs.begin();
            while (ite != funcs.end())
            {
                if (ite->target_type() == f.target_type() &&
                    ite->template target<void(*)(T1, T2, T3, T4, T5)>() == f.template target<void(*)(T1, T2, T3, T4, T5)>())
                {
                    break;
                }
                
                ++ite;
            }
            
            if (ite != funcs.end())
            {
                funcs.erase(ite);
            }
            
            return *this;
        }
        
        Event<void(T1, T2, T3, T4, T5)>& operator+=(std::function<void(T1, T2, T3, T4, T5)> f)
        {
            this->funcs.push_back(f);
            return *this;
        }
        
        Event<void(T1, T2, T3, T4, T5)>& operator+=(Event<void(T1, T2, T3, T4, T5)> &sf)
        {
            for (auto &f : sf.funcs)
            {
                this->funcs.push_back(f);
            }
            
            return *this;
        }
        
        void clear()
        {
            funcs.clear();
        }
        
        operator bool()
        {
            for (auto &f : this->funcs)
            {
                if (f)
                    return true;
            }
            
            return false;
        }
        
        void operator()(T1 p1, T2 p2, T3 p3, T4 p4, T5 p5)
        {
            std::list<std::function<void(T1, T2, T3, T4, T5)>> _copy(funcs);
            for (auto &f : _copy)
            {
                if (f)
                    f(p1, p2, p3, p4, p5);
            }
        }
        
    private:
        // Not allowed to copy
        Event<void(T1, T2, T3, T4, T5)>(const Event<void(T1, T2, T3, T4, T5)> &e) {}
        Event<void(T1, T2, T3, T4, T5)>& operator=(const Event<void(T1, T2, T3, T4, T5)> &e) {return *this;}
    };
}