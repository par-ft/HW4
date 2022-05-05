template <typename T>
UniquePtr<T>::UniquePtr(T *p) : _p{p}
{
}

template <typename T>
UniquePtr<T>::UniquePtr() : _p{nullptr}
{
}

template <typename T>
UniquePtr<T>::UniquePtr(const UniquePtr<T> &Unique_Ptr)
{
    static_assert(_p, "cannot copy a Unique Pointer");
}

template <typename T>
UniquePtr<T> &UniquePtr<T>::operator=(const UniquePtr<T> &Unique_Ptr)
{
    static_assert(_p, "cannot copy a Unique Pointer");
    return *this;
}

template <typename T>
UniquePtr<T>::~UniquePtr()
{
    if (_p)
        delete _p;

    _p = nullptr;
}

template <typename T>
T *make_unique(T i)
{
    return new T{i};
}

template <typename T>
void UniquePtr<T>::reset()
{
    if (_p)
        delete _p;

    _p = nullptr;
}

template <typename T>
void UniquePtr<T>::reset(T *p)
{
    if (_p)
        delete _p;

    _p = p;
}

template <typename T>
T *UniquePtr<T>::release()
{
    T *ptr{_p};
    _p = nullptr;

    return ptr;
}
