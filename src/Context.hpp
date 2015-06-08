
namespace ccHelp
{
    template <typename T>
    ContextValue ContextValue::makeCustom(const T &v)
    {
        ContextValue cv;
        cv.type = CUSTOM_HOLDER;
        cv.vCustomHolder = new CustomHolder<T>(v);
        
        return cv;
    }
    
    template <typename T>
    T* ContextValue::asPointer() const
    {
        assert(type == VOID_POINTER);
        return static_cast<T*>(vVoidPointer);
    }
    
    template <typename T>
    bool ContextValue::asCustom(T &t) const
    {
        assert(type == CUSTOM_HOLDER);
        
        auto *p = dynamic_cast<CustomHolder<T>*>(vCustomHolder);
        if (!p)
            return false;
        
        t = p->get();
        return true;
    }
    
    template <typename T>
    Context& Context::putPointer(const std::string &k, T *v)
    {
        valueMap[k] = ContextValue((void *) v);
    }
    
    template <typename T>
    Context& Context::putCustom(const std::string &k, const T& v)
    {
        valueMap[k] = ContextValue::makeCustom<T>(v);
    }
    
    template <typename T>
    T* Context::getPointer(const std::string &k) const
    {
        return valueMap.at(k).asPointer<T>();
    }
    
    template <typename T>
    bool Context::getCustom(const std::string &k, T& t) const
    {
        return valueMap.at(k).asCustom<T>(t);
    }
}