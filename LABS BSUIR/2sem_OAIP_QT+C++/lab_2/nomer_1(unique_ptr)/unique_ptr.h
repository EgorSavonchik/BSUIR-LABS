#pragma once
#include <utility>
#include <type_traits>
#include <memory>
#include <iostream>

template<class T>
class unique_ptr
{
	T* ptr = nullptr;

public:

	unique_ptr()
	{

	}
	
	unique_ptr(T* input) : ptr(input) {};
	
	~unique_ptr()
	{ 
		if (ptr == nullptr)
		{
			return;
		}
		
		delete ptr;
		ptr = nullptr;
	}

	unique_ptr(const unique_ptr& input) = delete;
	unique_ptr operator= (const unique_ptr& input) = delete;

	unique_ptr(unique_ptr&& input) noexcept : ptr(input.ptr) 
	{
		input.ptr = nullptr;
	}

	unique_ptr& operator= (unique_ptr&& input) noexcept
	{
		delete ptr;
		ptr = input.ptr;
		input.ptr = nullptr;

		return *this;
	}

	T* operator->() const
	{
		return ptr;
	}

	T& operator*() const
	{
		return *ptr;
	}

	bool operator ==(unique_ptr<T>& other) const
	{
		return ptr == other.ptr;
	}

	bool operator !=(unique_ptr<T>& other) const
	{
		return !(ptr == other.ptr);
	}

	bool operator <(unique_ptr<T>& other) const
	{
		return ptr < other.ptr;
	}

	bool operator >(unique_ptr<T>& other) const
	{
		return other < *this;
	}

	bool operator <=(unique_ptr<T>& other) const
	{
		return !(*this > other);
	}

	bool operator >=(unique_ptr<T>& other) const
	{
		return !(*this < other);
	}

	T* get() const
	{
		return ptr;
	}

	operator bool() const
	{
		return ptr != nullptr;
	}

	T* release()
	{
		T* tmp = ptr;
		ptr = nullptr;

		return tmp;
	}

	void reset(T* ptr)
	{
		this->~unique_ptr();

		*this = unique_ptr<T>(ptr);
	}

	void swap(unique_ptr<T>& other)
	{
		unique_ptr<T> tmp = std::move(*this);
		*this = std::move(other);
		other = std::move(tmp);
	}
};


template<class T>
class unique_ptr<T[]>
{
	T* ptr = nullptr;
public:	

	unique_ptr()
	{

	}

	unique_ptr(T* input) : ptr(input) {};

	~unique_ptr()
	{
		if (ptr == nullptr)
		{
			return;
		}
		
		delete[] ptr;
		ptr = nullptr;
	}

	unique_ptr(const unique_ptr& input) = delete;
	unique_ptr operator= (const unique_ptr& input) = delete;

	unique_ptr(unique_ptr&& input) noexcept : ptr(input.ptr)
	{
		input.ptr = nullptr;
	}

	unique_ptr& operator= (unique_ptr&& input) noexcept
	{
		delete ptr;
		ptr = input.ptr;
		input.ptr = nullptr;

		return *this;
	}

	T* operator->() const
	{
		return ptr;
	}

	T& operator*() const
	{
		return *ptr;
	}

	T& operator[] (int i) const
	{
		return ptr[i];
	}

	bool operator ==(unique_ptr<T[]>& other) const
	{
		return ptr == other.ptr;
	}

	bool operator !=(unique_ptr<T[]>& other) const
	{
		return !(ptr == other.ptr);
	}

	bool operator <(unique_ptr<T[]>& other) const
	{
		return ptr < other.ptr;
	}

	bool operator >(unique_ptr<T[]>& other) const
	{
		return other < *this;
	}

	bool operator <=(unique_ptr<T[]>& other) const
	{
		return !(*this > other);
	}

	bool operator >=(unique_ptr<T[]>& other) const
	{
		return !(*this < other);
	}

	operator bool() const
	{
		return ptr != nullptr;
	}

	T* get() const
	{
		return ptr;
	}

	void reset(T* ptr)
	{
		this->~unique_ptr();

		*this = unique_ptr<T[]>(ptr);
	}

	void swap(unique_ptr<T[]>& other)
	{
		unique_ptr<T[]> tmp = std::move(*this);
		*this = std::move(other);
		other = std::move(tmp);
	}

	T* release()
	{
		T* tmp = ptr;
		ptr = nullptr;

		return tmp;
	}
};


template<class T, class... Args>
typename std::enable_if<!std::is_array<T>::value,unique_ptr<T>>::type make_unique(Args&& ...args)
{
	return unique_ptr<T>(new T(std::forward<Args>(args)...));
}

template <class T>
typename std::enable_if<std::is_array<T>::value,unique_ptr<T>>::type make_unique(std::size_t n)
{
	typedef typename std::remove_extent<T>::type RT;
	return unique_ptr<T>(new RT[n]);
}


template<class T>
std::ostream& operator << (std::ostream& os, const unique_ptr<T>& p)
{
	return os << p.get();
}