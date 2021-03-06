#ifndef SHARED_PTR
#define SHARED_PTR

#include <iostream>

template <typename T>
class SharedPtr
{
public:
    SharedPtr(T *);
    SharedPtr();
    SharedPtr(const SharedPtr<T> &);
    SharedPtr<T> &operator=(const SharedPtr<T> &);
    ~SharedPtr();

    T *const &get() const { return _p; }
    T &operator*() const { return *_p; }
    size_t use_count();
    T *operator->() const { return _p; }
    void reset();
    void reset(T *);
    operator bool() const { return static_cast<bool>(_p); }

private:
    T *_p;
    size_t *cnt{nullptr};
};

template <typename T>
T *make_unique(T);

#include "shared_ptr.hpp"

#endif // SHARED_PTR
