template <typename T>
SharedPtr<T>::SharedPtr(T *p) : _p{p}
{
    if (_p)
        cnt = new size_t{1};
}

template <typename T>
SharedPtr<T>::SharedPtr() : _p{nullptr}
{
}

template <typename T>
SharedPtr<T>::SharedPtr(const SharedPtr<T> &Shared_Ptr)
{
    _p = Shared_Ptr._p;
    cnt = &(++(*(Shared_Ptr.cnt)));
}

template <typename T>
SharedPtr<T> &SharedPtr<T>::operator=(const SharedPtr<T> &Shared_Ptr)
{
    if (this == &Shared_Ptr)
        return *this;

    if (cnt)
        if (*cnt == 1)
        {
            delete cnt;
            delete _p;
        }
        else
        {
            --(*cnt);
        }

    _p = Shared_Ptr._p;
    cnt = &(++(*(Shared_Ptr.cnt)));

    return *this;
}

template <typename T>
SharedPtr<T>::~SharedPtr()
{
    if (cnt)
        if (*cnt == 1)
        {
            delete cnt;
            delete _p;
        }
        else
        {
            --(*cnt);
        }

    _p = nullptr;
    cnt = nullptr;
}

template <typename T>
T *make_shared(T i)
{
    return new T{i};
}

template <typename T>
size_t SharedPtr<T>::use_count()
{
    if (cnt)
        return *cnt;
    else
        return 0;
}

template <typename T>
void SharedPtr<T>::reset()
{
    if (cnt)
        if (*cnt == 1)
        {
            delete cnt;
            delete _p;
        }
        else
        {
            --(*cnt);
        }

    _p = nullptr;
    cnt = nullptr;
}

template <typename T>
void SharedPtr<T>::reset(T *p)
{
    if (cnt)
        if (*cnt == 1)
        {
            delete cnt;
            delete _p;
        }
        else
        {
            --(*cnt);
        }

    _p = p;
    cnt = new size_t{1};
}
