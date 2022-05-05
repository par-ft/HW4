#ifndef UNIQUE_PTR
#define UNIQUE_PTR

#include <iostream>

template <typename T>
class UniquePtr
{
public:
    UniquePtr(T *);
    UniquePtr();
    UniquePtr(const UniquePtr<T> &);
    UniquePtr<T> &operator=(const UniquePtr<T> &);
    ~UniquePtr();

    T *const &get() const { return _p; }
    T &operator*() const { return *_p; }
    T *operator->() const { return _p; }
    void reset();
    void reset(T *);
    operator bool() const { return static_cast<bool>(_p); }
    T *release();

private:
    T *_p;
};

template <typename T>
T *make_unique(T);

#include "unique_ptr.hpp"

#endif // UNIQUE_PTR
