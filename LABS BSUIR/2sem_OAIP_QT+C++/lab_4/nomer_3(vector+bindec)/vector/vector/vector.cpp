#include <iostream>
#include <memory>

template<class T>
class vector
{
    T* arr = nullptr;
    size_t sz = 0;
    size_t cap = 0;

public:

    vector()
    {
        
    }

    ~vector()
    {
        
        std::cout << "I delete" << '\n';
        
        if (sz != 0)
        {          
            sz = 0;
            cap = 0;
            
            if (!arr)
            {
                delete[] arr;
            }
                 
            arr = nullptr;
        }
    }

    vector& operator=(const vector& other)
    {
        if (other.arr == arr)
        {
            return *this;
        }
        
        this->~vector();

        T* newArr = new T[other.cap];

        for (int i = 0; i < other.sz; i++)
        {
            newArr[i] = other.arr[i];
        }

        sz = other.sz;
        cap = other.cap;
        arr = newArr;

        return *this;
    }

    void reserve(size_t n)
    {
        if (cap >= n)
        {
            return;
        }

        T* newArr = new T[n];

        for (size_t i = 0; i < sz; i++)
        {
            newArr[i]  = arr[i];
        }

        if (sz != 0)
        {
            delete[] arr;
        }

        arr = newArr;
        cap = n;
    }

    void resize(size_t len, const T& val)
    {
        if (len == sz)
        {
            return;
        }

        this->reserve(len);

        T* newArr = new T[len];

        for (int i = 0; i < len; i++)
        {
            if (sz > i)
            {
                newArr[i] =  arr[i];
            }
            else
            {
                newArr[i] = val;
            }
        }

        if (sz != 0)
        {
            delete[] arr;
        }

        arr = newArr;
        sz = len;
    }


    void resize(size_t len)
    {
        if (len == sz)
        {
            return;
        }

        this->reserve(len);

        T* newArr = new T[len];

        for (int i = 0; i < len; i++)
        {
            if (sz > i)
            {
                newArr[i] =  arr[i];
            }
        }

        if (sz != 0)
        {
            delete[] arr;
        }

        arr = newArr;
        sz = len;
    }

    void assign(size_t len, const T& val)
    {
        this->clear();

        this->resize(len, val);
    }

    template<class T>
    void push_back(T&& value)
    {
        if (cap == sz)
        {
            if (sz != 0)
            {
                this->reserve(sz * 2);
            }
            else
            {
                this->reserve(1);
            }
        }

        arr[sz] = std::forward<T>(value);
        sz++;
    }

    template<class... Args>
    void emplace_back(Args&&... args)
    {
        if (cap == sz)
        {
            if (sz != 0)
            {
                this->reserve(sz * 2);
            }
            else
            {
                this->reserve(1);
            }
        }

        arr[sz] = T(std::forward<Args>(args)...);
        sz++;
    }

    void erase(size_t pos, int len = 1)
    {
        T* newArr = reinterpret_cast<T*>(new char[(sz - len) * sizeof(T)]);

        for (int i = 0, j = 0; i < sz; i++)
        {
            if (i < pos || i >= (pos + len))
            {
                new(newArr + j) T(arr[i]);
                j++;
            }
            else
            {
                arr[i].~T();
            }
        }

        if (sz != 0)
        {
            delete[] arr;
        }

        arr = newArr;
        sz = sz - len;
    }

    void insert(size_t pos, const T& val)
    {
        if (sz == cap)
        {
            this->reserve(2 * sz);
        }

        T* newArr = reinterpret_cast<T*>(new char[(sz + 1) * sizeof(T)]);

        for (int i = 0, j = 0; i <= sz; i++)
        {
            if (i != pos)
            {
                new(newArr + i) T(arr[j]);
                j++;
            }
            else
            {
                new(newArr + i) T(val);
            }
        }

        if (sz != 0)
        {
            delete[] arr;
        }

        arr = newArr;
        sz = sz + 1;
    }

    template<class... Args>
    void emplace(size_t pos, Args&&... args)
    {
        if (sz == cap)
        {
            this->reserve(2 * sz);
        }

        T* newArr = reinterpret_cast<T*>(new char[(sz + 1) * sizeof(T)]);

        for (int i = 0, j = 0; i <= sz; i++)
        {
            if (i != pos)
            {
                new(newArr + i) T(arr[j]);
                j++;
            }
            else
            {
                new(newArr + i) T(std::forward<Args>(args)...);
            }
        }

        if (sz != 0)
        {
            delete[] arr;
        }

        arr = newArr;
        sz = sz + 1;
    }

    void swap(vector& other)
    {
        T* temp_arr = arr;
        size_t temp_sz = sz;
        size_t temp_cap = cap;

        arr = other.arr;
        cap = other.cap;
        sz = other.sz;

        other.arr = temp_arr;
        other.cap = temp_cap;
        other.sz = temp_sz;
    }

    T& front()
    {
        return arr[0];
    }

    T& back()
    {
        return arr[sz - 1];
    }

    struct iterator
    {
        T* current = nullptr;

        iterator(T* input)
        {
            current = input;
        }

        iterator(const iterator& input)
        {
            current = input.current;
        }

        iterator& operator++()
        {
            current++;

            return *this;
        }

        iterator& operator++(int)
        {
            iterator tmp = *this;

            current++;

            return tmp;
        }

        iterator& operator--()
        {
            current--;

            return *this;
        }

        iterator& operator--(int)
        {
            iterator tmp = *this;

            current--;

            return tmp;
        }

        T& operator*()
        {
            return *current;
        }
        
        bool operator==(iterator other)
        {
            return current == other.current ? true : false;
        }

        bool operator!=(iterator other)
        {
            return !(*this == other);
        }
    };

    struct const_iterator 
    {
        T* current = nullptr;

        const_iterator(T* input)
        {
            current = input;
        }

        const_iterator(const iterator& input)
        {
            current = input.current;
        }

        const_iterator& operator++()
        {
            current++;
        }

        const_iterator& operator++(int)
        {
            const_iterator tmp = *this;

            current++;

            return tmp;
        }

        const_iterator& operator--()
        {
            current--;

            return *this;
        }

        const_iterator& operator--(int)
        {
            const_iterator tmp = *this;

            current--;

            return tmp;
        }

        const T& operator*() const
        {
            return *current;
        }

        bool operator==(const_iterator other)
        {
            return current == other.current ? true : false;
        }

        bool operator!=(const_iterator other)
        {
            return !(*this == other);
        }
    };

    struct reverse_iterator
    {
        T* current = nullptr;

        reverse_iterator(T* input)
        {
            current = input;
        }

        reverse_iterator(const reverse_iterator& input)
        {
            current = input.current;
        }

        reverse_iterator& operator++()
        {
            current--;

            return *this;
        }

        reverse_iterator& operator++(int)
        {
            reverse_iterator tmp = *this;

            current--;

            return tmp;
        }

        reverse_iterator& operator--()
        {
            current++;

            return *this;
        }

        reverse_iterator& operator--(int)
        {
            reverse_iterator tmp = *this;

            current++;

            return tmp;
        }

        T& operator*()
        {
            return *current;
        }

        bool operator==(reverse_iterator other)
        {
            return current == other.current ? true : false;
        }

        bool operator!=(reverse_iterator other)
        {
            return !(*this == other);
        }
    };

    struct const_reverse_iterator
    {
        T* current = nullptr;

        const_reverse_iterator(T* input)
        {
            current = input;
        }

        const_reverse_iterator(const reverse_iterator& input)
        {
            current = input.current;
        }

        const_reverse_iterator& operator++()
        {
            current--;
        }

        const_reverse_iterator& operator++(int)
        {
            const_reverse_iterator tmp = *this;

            current--;

            return tmp;
        }

        const_reverse_iterator& operator--()
        {
            current++;

            return *this;
        }

        const_reverse_iterator& operator--(int)
        {
            const_reverse_iterator tmp = *this;

            current++;

            return tmp;
        }

        const T& operator*() const
        {
            return *current;
        }

        bool operator==(const_reverse_iterator other)
        {
            return current == other.current ? true : false;
        }

        bool operator!=(const_reverse_iterator other)
        {
            return !(*this == other);
        }
    };

    iterator begin() const
    {
        return iterator(arr);
    }

    iterator end() const
    {
        return iterator(arr + sz);
    }

    const_iterator cbegin() const
    {
        return iterator(arr);
    }

    const_iterator cend() const
    {
        this->reserve(sz + 1);
        
        return iterator(arr + sz);
    }

    reverse_iterator rbegin() const
    {
        return reverse_iterator(arr + sz - 1);
    }

    reverse_iterator rend() const
    {
        return reverse_iterator(arr - 1);
    }

    const_reverse_iterator crbegin() const
    {
        return reverse_iterator(arr + sz - 1);
    }

    const_reverse_iterator crend() const
    {
        return reverse_iterator(arr - 1);
    }

    T* data()
    {
        return arr;
    }

    size_t capacity() const
    {
        return cap;
    }

    size_t size() const
    {
        return sz;
    }

    T& operator[](int i) const
    {
        return arr[i];
    }

    T& at(int i)
    {
        if (i >= 0 && i < sz)
        {
            return arr[i];
        }

        throw std::out_of_range;
    }

    bool empty() const
    {
        return sz == 0;
    }

    void pop_back()
    {
        sz--;

        arr[sz].~T();
    }

    void clear()
    {
        this->~vector();
    }

    size_t max_size() const
    {
        return static_cast<size_t>(pow(2, 64) / sizeof(T));
    }
};


int main()
{
    vector<vector<char>> A;
    vector<char> temp;
    A.resize(5, temp);

    
    for (int i = 0; i < 5; i++)
    {
        A[i].resize(200, 'q');
    }

    A[4];
}
