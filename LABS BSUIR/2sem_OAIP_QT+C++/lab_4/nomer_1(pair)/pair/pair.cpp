#include <iostream>
#include <memory>


template<class T1, class T2>
struct pair
{
    T1 first;
    T2 second;

    pair()
    {

    }

    pair(const T1& fir, const T2& sec)
    {
        first = fir;
        second = sec;
    }

    pair(pair& other)
    {
        first = other.first;
        second = other.second;
    }

    pair operator=(pair& other)
    {
        first = other.first;
        second = other.second;

        return *this;
    }

    pair(T1&& fir, T2&& sec)
    {
        first = std::move(fir);
        second = std::move(sec);
    }

    pair(pair&& other)
    {
        first = std::move(other.first);
        second = std::move(other.second);
    }

    pair operator=(pair&& other)
    {
        first = std::move(other.first);
        second = std::move(other.second);

        return *this;
    }

    void swap(pair& other)
    {
        pair<T1, T2> temp = std::move(other);
        other = std::move(*this);
        *this = std::move(temp);
    }
};

/*pair<int, int> rwert()
{
    return pair<int, int>(3, 3);
}



int main()
{
    std::cout << "Hello World!\n";

    pair<int, int> p(4, 4), r = rwert();

    r.swap(p);

    std::cout << p.first;
}*/

