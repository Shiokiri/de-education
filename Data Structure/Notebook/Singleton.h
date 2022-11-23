#ifndef SINGLETON_H
#define SINGLETON_H

#include <type_traits>

template<typename T>
class Singleton{
public:
    static T& get_instance()
        noexcept(std::is_nothrow_constructible<T>::value)
    {
        static T instance;
        return instance;
    }
    virtual ~Singleton() noexcept {}
    Singleton(const Singleton&) = delete;
    Singleton& operator = (const Singleton&) = delete;
protected:
    Singleton() {}
};

#endif // SINGLETON_H
