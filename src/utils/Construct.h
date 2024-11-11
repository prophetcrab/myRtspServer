//
// Created by crab on 2024/10/28.
//

#ifndef CONSTRUCT_H
#define CONSTRUCT_H

#include <new>

//在特定内存位置上构造或销毁对象，与内存池连用

template <class T>
inline void destroy(T* pointer)
{
    pointer->~T();
}

template <class T>
inline void construct(T* p)
{
    new (p) T();
}

template <class T, class T1>
inline void construct(T* p, const T1& a1)
{
    new (p) T(a1);
}

template <class T, class T1, class T2>
inline void construct(T* p, const T1& a1, const T2& a2)
{
    new (p) T(a1, a2);
}

template <class T, class T1, class T2, class T3>
inline void construct(T* p, const T1& a1, const T2& a2, const T3& a3)
{
    new (p) T(a1, a2, a3);
}

template <class T, class T1, class T2, class T3, class T4>
inline void construct(T* p, const T1& a1, const T2& a2, const T3& a3, const T4& a4)
{
    new (p) T(a1, a2, a3, a4);
}

#endif //CONSTRUCT_H
