#pragma once
#include <utility>
#include <type_traits>
#include <memory>

template<class T>
class weak_ptr;

template<class T>
class unique_ptr;

struct control_block
{
	int* shared_count = nullptr;
	int* weak_count = nullptr;
};

template<class T>
class shared_ptr
{
	control_block* cbloc = nullptr;
	T* object = nullptr;

	friend class weak_ptr<T>;

public:

	shared_ptr()
	{

	}

	shared_ptr(T* input) 
	{
		cbloc = new control_block;
		cbloc->shared_count = new int(1);
		cbloc->weak_count = new int(0); 
		object = input;
	}

	shared_ptr(weak_ptr<T> input)
	{
		cbloc = input.cbloc;
		object = input.object;

		(*(cbloc->shared_count))++;
	}

	shared_ptr(unique_ptr<T>&& input)
	{
		*this = input.release();
	}
	
	~shared_ptr()
	{
		if (cbloc == nullptr)
		{
			return;
		}
		
		(*(cbloc->shared_count))--;
		

		if (*(cbloc->shared_count) == 0 && *(cbloc->weak_count) == 0)
		{
			delete cbloc->shared_count;
			delete cbloc->weak_count;
			delete object;
			delete cbloc;

			object = nullptr;
		}
		else if (*(cbloc->shared_count) == 0)
		{
			delete object;

			object = nullptr;
		
		}
		
		cbloc = nullptr;
		object = nullptr;
	}

	shared_ptr(const shared_ptr& other) 
	{
		this->~shared_ptr();
		
		cbloc = other.cbloc;
		object = other.object;

		(*(cbloc->shared_count))++;
	}

	shared_ptr operator= (const shared_ptr& other)
	{
		this->~shared_ptr();

		cbloc = other.cbloc;
		object = other.object;

		(*(cbloc->shared_count))++;

		return *this;
	}

	shared_ptr(shared_ptr&& other) noexcept : cbloc(other.cbloc), object(other.object)
	{
		other.cbloc = nullptr;
		other.object = nullptr;
	}

	shared_ptr operator= (shared_ptr&& other) noexcept
	{
		this->~shared_ptr();
		
		cbloc = other.cbloc;
		object = other.object;

		other.cbloc = nullptr;
		other.object = nullptr;

		return *this;
	}

	T& operator*()
	{
		return *object;
	}

	T* operator->()
	{
		return object;
	}

	bool operator ==(shared_ptr<T> other) const
	{
		return object == other.object;
	}

	bool operator !=(shared_ptr<T> other) const
	{
		return !(object == other.object);
	}

	bool operator <(shared_ptr<T> other) const
	{
		return object < other.object;
	}

	bool operator >(shared_ptr<T> other) const
	{
		return other < *this;
	}

	bool operator <=(shared_ptr<T> other) const
	{
		return !(*this > other);
	}

	bool operator >=(shared_ptr<T> other) const
	{
		return !(*this < other);
	}

	size_t use_count() const
	{
		return *(cbloc->shared_count);
	}

	operator bool() const
	{
		return !(object == nullptr);
	}

	void reset(T* ptr = nullptr)
	{
		this->~shared_ptr();

		*this = shared_ptr<T>(ptr);
	}

	void swap(shared_ptr<T>& other)
	{
		shared_ptr<T> tmp = std::move(*this);
		*this = std::move(other);
		other = std::move(tmp);
	}
};


template<class T>
class shared_ptr<T[]>
{
	control_block* cbloc = nullptr;
	T* object = nullptr;

	friend class weak_ptr<T[]>;

public:

	shared_ptr()
	{

	}

	shared_ptr(T* input)
	{
		cbloc = new control_block;
		cbloc->shared_count = new int(1);
		cbloc->weak_count = new int(0);
		object = input;
	}

	shared_ptr(weak_ptr<T[]> input)
	{
		cbloc = input.cbloc;
		object = input.object;

		(*(cbloc->shared_count))++;
	}

	shared_ptr(unique_ptr<T[]>&& input)
	{
		*this = input.release();
	}

	~shared_ptr()
	{
		if (cbloc == nullptr)
		{
			return;
		}

		(*(cbloc->shared_count))--;


		if (*(cbloc->shared_count) == 0 && *(cbloc->weak_count) == 0)
		{
			delete cbloc->shared_count;
			delete cbloc->weak_count;
			delete[] object;
			delete cbloc;

			object = nullptr;
		}
		else if (*(cbloc->shared_count) == 0)
		{
			delete[] object;

			object = nullptr;
		}

		cbloc = nullptr;
		object = nullptr;
	}

	shared_ptr(const shared_ptr& other)
	{
		this->~shared_ptr();

		cbloc = other.cbloc;
		object = other.object;

		(*(cbloc->shared_count))++;
	}

	shared_ptr operator= (const shared_ptr& other)
	{
		this->~shared_ptr();

		cbloc = other.cbloc;
		object = other.object;

		(*(cbloc->shared_count))++;

		return *this;
	}

	shared_ptr(shared_ptr&& other) noexcept : cbloc(other.cbloc), object(other.object)
	{
		other.cbloc = nullptr;
		other.object = nullptr;
	}

	shared_ptr operator= (shared_ptr&& other) noexcept
	{
		this->~shared_ptr();

		cbloc = other.cbloc;
		object = other.object;

		other.cbloc = nullptr;
		other.object = nullptr;

		return *this;
	}

	T& operator*()
	{
		return *object;
	}

	T* operator->()
	{
		return object;
	}

	bool operator ==(shared_ptr<T[]> other) const
	{
		return object == other.object;
	}

	bool operator !=(shared_ptr<T[]> other) const
	{
		return !(object == other.object);
	}

	bool operator <(shared_ptr<T[]> other) const
	{
		return object < other.object;
	}

	bool operator >(shared_ptr<T[]> other) const
	{
		return other < *this;
	}

	bool operator <=(shared_ptr<T[]> other) const
	{
		return !(*this > other);
	}

	bool operator >=(shared_ptr<T[]> other) const
	{
		return !(*this < other);
	}

	size_t use_count() const
	{
		return *(cbloc->shared_count);
	}

	operator bool() const
	{
		return !(object == nullptr);
	}

	T& operator[](int i)
	{
		return object[i];
	}

	void reset(T* ptr = nullptr)
	{
		this->~shared_ptr();

		*this = shared_ptr<T[]>(ptr);
	}

	void swap(shared_ptr<T>& other)
	{
		shared_ptr<T[]> tmp = std::move(*this);
		*this = std::move(other);
		other = std::move(tmp);
	}
};

template<class T, class... Args>
typename std::enable_if<!std::is_array<T>::value, shared_ptr<T>>::type make_shared(Args&& ...args)
{
	return shared_ptr<T>(new T(std::forward<Args>(args)...));
}

template <class T>
typename std::enable_if<std::is_array<T>::value, shared_ptr<T>>::type make_shared(std::size_t n)
{
	typedef typename std::remove_extent<T>::type RT;
	return shared_ptr<T>(new RT[n]);
}


template<class T>
std::ostream& operator << (std::ostream& os, const shared_ptr<T>& p)
{
	return os << p.get();
}