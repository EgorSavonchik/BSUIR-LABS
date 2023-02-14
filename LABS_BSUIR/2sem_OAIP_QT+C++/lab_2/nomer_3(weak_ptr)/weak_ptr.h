#pragma once
#include <utility>
#include <type_traits>
#include <memory>

template<class T>
class shared_ptr;

struct control_block
{
	int* shared_count = nullptr;
	int* weak_count = nullptr;
};

template<class T>
class weak_ptr
{
	control_block* cbloc = nullptr;
	T* object = nullptr;

	friend class shared_ptr<T>;
public:

	weak_ptr()
	{

	}

	weak_ptr(shared_ptr<T> input)
	{
		cbloc = input.cbloc;
		object = input.object;
		
		(*(cbloc->weak_count))++;
	}

	~weak_ptr()
	{
		if (cbloc == nullptr)
		{
			return;
		}
		
		(*(cbloc->weak_count))--;

		if (*(cbloc->shared_count) == 0 && *(cbloc->weak_count) == 0)
		{
			delete cbloc->shared_count;
			delete cbloc->weak_count;
			delete cbloc;
		}

		cbloc = nullptr;
		object = nullptr;
	}

	weak_ptr(const weak_ptr& other)
	{
		cbloc = other.cbloc;
		object = other.object;
		(*(cbloc->weak_count))++;
	}

	weak_ptr operator= (const weak_ptr& other)
	{
		cbloc = other.cbloc;
		object = other.object;

		(*(cbloc->weak_count))++;

		return *this;
	}

	 weak_ptr(weak_ptr&& other) noexcept : cbloc(other.cbloc), object(other.object) 
	{
		other.cbloc = nullptr;
		other.object = nullptr;
	}

	weak_ptr operator= (weak_ptr&& other) noexcept
	{
		cbloc = other.cbloc;
		object = other.object;

		other.cbloc = nullptr;
		other.object = nullptr;

		return *this;
	}

	size_t use_count() const
	{
		if (cbloc == nullptr)
		{
			return 0;
		}
		
		return *(cbloc->shared_count);
	}

	bool expired() const
	{
		return this->use_count() == 0;
	}

	shared_ptr<T> lock()
	{
		return expired() ? shared_ptr<T>() : shared_ptr<T>(*this);
	}

	void reset()
	{
		this->~weak_ptr();
	}

	void swap(weak_ptr<T>& other)
	{
		weak_ptr<T> tmp = std::move(*this);
		*this = std::move(other);
		other = std::move(tmp);
	}
};

template<class T>
class weak_ptr<T[]>
{
	control_block* cbloc = nullptr;
	T* object = nullptr;

	friend class shared_ptr<T[]>;
public:

	weak_ptr()
	{

	}

	weak_ptr(shared_ptr<T[]> input)
	{
		cbloc = input.cbloc;
		object = input.object;

		(*(cbloc->weak_count))++;
	}

	~weak_ptr()
	{
		if (cbloc == nullptr)
		{
			return;
		}

		(*(cbloc->weak_count))--;

		if (*(cbloc->shared_count) == 0 && *(cbloc->weak_count) == 0)
		{
			delete cbloc->shared_count;
			delete cbloc->weak_count;
			delete cbloc;
	
			cbloc = nullptr;
		}

		cbloc = nullptr;
	}

	weak_ptr(weak_ptr&& other) : cbloc(other.cbloc), object(other.object)
	{
		other.cbloc = nullptr;
		other.object = nullptr;
	}

	weak_ptr operator= (weak_ptr&& other)
	{
		cbloc = other.cbloc;
		object = other.object;

		other.cbloc = nullptr;
		other.object = nullptr;

		return *this;
	}

	weak_ptr(const weak_ptr& other)
	{
		cbloc = other.cbloc;
		object = other.object;
		(*(cbloc->weak_count))++;
	}

	weak_ptr operator= (const weak_ptr& other)
	{
		cbloc = other.cbloc;
		object = other.object;

		(*(cbloc->weak_count))++;

		return *this;
	}

	size_t use_count() const
	{
		return *(cbloc->shared_count);
	}

	bool expired() const
	{
		return this->use_count() == 0;
	}

	shared_ptr<T[]> lock()
	{
		return expired() ? shared_ptr<T[]>() : shared_ptr<T[]>(*this);
	}

	void reset()
	{
		this->~weak_ptr();
	}

	void swap(weak_ptr<T[]>& other)
	{
		weak_ptr<T[]> tmp = std::move(*this);
		*this = std::move(other);
		other = std::move(tmp);
	}
};

