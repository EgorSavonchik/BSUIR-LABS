#include <iostream>
#include <type_traits>

namespace tool 
{
    void* memcpy(void* s1, const void* s2, size_t n)
    {
        char* dest = (char*)s1;
        const char* src = (const char*)s2;

        for (size_t i = 0; i < n; ++i)
        {
            dest[i] = src[i];
        }

        return (void*)dest;
    }

    void* memmove(void* s1, const void* s2, size_t n)
    {
        char* dest = (char*)s1;
        const char* src = (const char*)s2;

        char* buffer = new char[n];
        
        if (buffer != nullptr)
        {
            for (size_t i = 0; i < n; ++i)
            {
                buffer[i] = src[i];
            }

            for (size_t i = 0; i < n; ++i)
            {
                dest[i] = buffer[i];
            }

            delete[] buffer;

            return dest;
        }

        return nullptr;
    }

    size_t strlen(const char* s)
    {
        size_t length = 0;

        while (*s++) ++length;

        return length;
    }

    char* strcpy(char* s1, const char* s2)
    {
        char* tmp = s1;

        while (*s1++ = *s2++);

        return tmp;
    }

    char* strncpy(char* s1, const char* s2, size_t n)
    {
        char* tmp = s1;

        for (size_t i = 0; i < n; ++i)
        {
            *s1++ = *s2++;
        }

        return tmp;
    }

    char* strcat(char* s1, const char* s2)
    {
        size_t i, j;

        for (i = 0; s1[i] != '\0'; i++) {}

        for (j = 0; s2[j] != '\0'; j++)
        {
            s1[i + j] = s2[j];
        }

        s1[i + j] = '\0';
        return s1;
    }

    char* strncat(char* s1, const char* s2, size_t n)
    {

        char* dest = s1;

        while (*dest != '\0') dest++;

        while (n--)
        {
            if (!(*dest++ = *s2++))
            {
                return s1;
            }
        }

        *dest = '\0';

        return s1;
    }

    int memcmp(const void* s1, const void* s2, size_t n)
    {
        unsigned char* p = (unsigned char*)s1;
        unsigned char* q = (unsigned char*)s2;

        int charCompareStatus = 0;

        if (s1 == s2)
        {
            return charCompareStatus;
        }

        while (n > 0)
        {
            if (*p != *q)
            {
                charCompareStatus = (*p > *q) ? 1 : -1;
                break;
            }

            n--;
            p++;
            q++;
        }

        return charCompareStatus;
    }

    int strcmp(const char* s1, const char* s2)
    {
        while (*s1 && (*s1 == *s2))
        {
            s1++;
            s2++;
        }

        return *(const unsigned char*)s1 - *(const unsigned char*)s2;
    }

    int strncmp(const char* s1, const char* s2, size_t n)
    {
        while (n && *s1 && (*s1 == *s2))
        {
            ++s1;
            ++s2;
            --n;
        }

        if (n == 0)
        {
            return 0;
        }
        else
        {
            return (*(unsigned char*)s1 - *(unsigned char*)s2);
        }
    }

    size_t strxfrm(char* s1, const char* s2, size_t n)//не работает
    {
        size_t n2 = strlen(s2);

        if (n > n2)
        {
            strcpy(s1, s2);
        }

        return n2;
    }

    char* strtok(char* s1, char* s2)// хуйня
    {
        auto is_delim = [](char c, char* delim)
        {
            while (*delim != '\0')
            {
                if (c == *delim)
                    return 1;
                delim++;
            }
            return 0;
        };

        static char* backup_string;
        if (!s1)
        {
            s1 = backup_string;
        }
        if (!s1)
        {
            return nullptr;
        }
        while (true)
        {
            if (is_delim(*s1, s2))
            {
                s1++;
                continue;
            }
            if (*s1 == '\0')
            {
                return nullptr;
            }
            break;
        }

        char* ret = s1;

        while (true)
        {
            if (*s1 == '\0')
            {
                backup_string = s1;
                return ret;
            }
            if (is_delim(*s1, s2))
            {
                *s1 = '\0';
                backup_string = s1 + 1;
                return ret;
            }
            s1++;
        }
    }

    void* memset(void* s, int c, size_t n)
    {
        unsigned char* p = (unsigned char*)s;

        while (n--)
        {
            *p++ = (unsigned char)c;
        }
        return s;
    }
}




class string
{
	size_t cap = 15;

	union test {
		struct no_small_buffer_t {
			char* data;
			size_t size;
		} no_small_buffer;
		struct small_buffer_t {
			char data[sizeof(no_small_buffer_t)];
		} small_buffer;
	} base;

	friend std::ostream& operator << (std::ostream& os, const string& p);
    friend std::istream& operator>>(std::istream& stream, string& s);

public:

	string()
	{
		base.small_buffer.data[0] = '\0';
	}

	~string()
	{
		if (cap != 15)
		{
			delete[] base.no_small_buffer.data;
		}
        else
        {
            base.small_buffer.data[0] = '\0';
        }
	}

	string(const char* input)
	{
		this->~string();

		this->reserve(tool::strlen(input));

		if (cap == 15)
		{
            int i = 0;

			for ( ;i < tool::strlen(input); i++)
			{
				this->base.small_buffer.data[i] = input[i];
			}

            base.small_buffer.data[i] = '\0';
		}
		else
		{
			for (int i = 0; i <= tool::strlen(input); i++)
			{
				this->base.no_small_buffer.data[i] = input[i];
			}

			base.no_small_buffer.size = tool::strlen(input);
		}
	}

    string(string& input)
    {
        this->~string();

        if (input.cap == 15)
        {
            size_t i = 0;

            for ( ; input[i] != '\0'; i++)
            {
                base.small_buffer.data[i] = input[i];
            }

            base.small_buffer.data[i] = '\0';
        }
        else
        {
            this->reserve(input.base.no_small_buffer.size);

            for (int i = 0; input[i] != '\0'; i++)
            {
                base.no_small_buffer.data[i] = input[i];
            }

            base.no_small_buffer.size = input.size();
            base.no_small_buffer.data[input.base.no_small_buffer.size] = '\0';
        }  
    }

    string& operator= (const char* input)
    {
        this->~string();

        this->reserve(tool::strlen(input));

        if (cap == 15)
        {
            int i = 0;
            
            for ( ; i < tool::strlen(input); i++)
            {
                this->base.small_buffer.data[i] = input[i];
            }

            base.small_buffer.data[i] = '\0';
        }
        else
        {
            for (int i = 0; i <= tool::strlen(input); i++)
            {
                this->base.no_small_buffer.data[i] = input[i];
            }

            base.no_small_buffer.size = tool::strlen(input);
        }

        return *this;
    }

    string operator+=(const char& ch)
    {
        this->push_back(ch);

        return *this;
    }

    string& operator= (string& input)
    {
        this->~string();

        if (input.cap == 15)
        {
            size_t i = 0;

            for (; input[i] != '\0'; i++)
            {
                base.small_buffer.data[i] = input[i];
            }

            base.small_buffer.data[i] = '\0';
        }
        else
        {
            this->reserve(input.base.no_small_buffer.size);

            for (int i = 0; input[i] != '\0'; i++)
            {
                base.no_small_buffer.data[i] = input[i];
            }

            base.no_small_buffer.size = input.size();
            base.no_small_buffer.data[input.base.no_small_buffer.size] = '\0';
        }

        return *this;
    }

    string& operator= (string&& input)
    {
        this->~string();

        if (input.cap == 15)
        {
            size_t i = 0;

            for (; input[i] != '\0'; i++)
            {
                base.small_buffer.data[i] = std::move(input[i]);
            }

            base.small_buffer.data[i] = '\0';
        }
        else
        {
            this->reserve(input.base.no_small_buffer.size);

            for (int i = 0; input[i] != '\0'; i++)
            {
                base.no_small_buffer.data[i] = std::move(input[i]);
            }

            base.no_small_buffer.data[input.base.no_small_buffer.size] = '\0';
        }

        return *this;
    }


    string operator+ (const string& input)
    {
        string newstr;
        
        for (int i = 0; i < this->size(); i++)
        {
            newstr.push_back((*this)[i]);
        }

        for (int i = 0; i < input.size(); i++)
        {
            newstr.push_back(input[i]);
        }

        return newstr;
    }

    string operator+=(const string& input)
    {
        for (int i = 0; i < input.size(); i++)
        {
            this->push_back(input[i]);
        }

        return *this;
    }

    string operator+ (const char* input)
    {
        size_t len = strlen(input);
        
        for (int i = 0; i < len; i++)
        {
            this->push_back(input[i]);
        }

        return *this;
    }

    string operator+=(const char* input)
    {
        size_t len = strlen(input);

        for (int i = 0; i < len; i++)
        {
            this->push_back(input[i]);
        }

        return *this;
    }

    bool operator==(const string& input)
    {
        return strcmp(this->c_str(), input.c_str());
    }
    
    bool operator==(const char* input)
    {
        return strcmp(this->c_str(), input);
    }

    void resize(size_t newLen, char agg = ' ')
    {
        if (newLen >= strlen(this->c_str()))
        {
            this->reserve(newLen);

            for (size_t i = strlen(this->c_str()); i < newLen; i++)
            {
                this->push_back(agg);
            }
        }
        else
        {
            char* newArr = new char[newLen];

            if (cap == 15)
            {
                for (int i = 0; i < newLen; i++)
                {
                    newArr[i] = base.small_buffer.data[i];
                }  
            }
            else
            {
                for (int i = 0; i < newLen; i++)
                {
                    newArr[i] = base.no_small_buffer.data[i];
                }
                
                delete[] base.no_small_buffer.data;
            }

            if (newLen < 16)
            {
                for (int i = 0; i < newLen; i++)
                {
                    base.small_buffer.data[i] = newArr[i];
                }

                base.small_buffer.data[newLen] = '\0';
            }
            else
            {
                base.no_small_buffer.data = newArr;
                base.no_small_buffer.data[newLen] = '\0';
            }
        }
    }

    bool operator<(const string& str)
    {
        if (this->size() > str.size())
        {
            return false;
        }

        if (this->size() < str.size())
        {
            return true;
        }
        
        for (int i = 0; i < (this->size() < str.size() ? this->size() : str.size()); i++)
        {
            if (this->c_str()[i] > str[i])
            {
                return false;
            }
        }

        return true;
    }

    bool operator>(const string& str)
    {
        if (this->size() < str.size())
        {
            return false;
        }

        if (this->size() > str.size())
        {
            return true;
        }

        for (int i = 0; i < (this->size() < str.size() ? this->size() : str.size()); i++)
        {
            if (this->c_str()[i] < str[i])
            {
                return false;
            }
        }

        return true;
    }

	void reserve(size_t n)
	{
		if (n <= cap)
		{
			return;
		}

		size_t newCap = cap * 1.5;

		for (; newCap <= n; )
		{
			newCap *= 1.5;// произвольное число, как в стринге не вычислить
		}

		char* newArr = new char[newCap + 1];
		
		if (cap == 15)
		{
			size_t i = 0;
			
			for ( ; base.small_buffer.data[i] != '\0'; i++)
			{
				newArr[i] = base.small_buffer.data[i];
			}

			newArr[i] = '\0';

			base.no_small_buffer.size = i;
		}
		else
		{
			for (int i = 0; i < base.no_small_buffer.size; i++)
				{
					newArr[i] = base.no_small_buffer.data[i];
				}

            newArr[base.no_small_buffer.size] = '\0';
		}
		
        if (cap != 15)
        {
            delete[] base.no_small_buffer.data;
        }

		base.no_small_buffer.data = newArr;
        cap = newCap;

        newArr = nullptr;
	}

    char* c_str() const
    {
        if (cap != 15)
        {
            return base.no_small_buffer.data;
        }
    }

    const char* c_str()
    {
        if (cap == 15)
        {
            return base.small_buffer.data;
        }
    }

	void push_back(const char& x)
	{
		if (cap == 15)
		{
			size_t buffer_size = strlen(base.small_buffer.data);

			if (buffer_size == 15)
			{
				this->reserve(cap * 1.5);

				base.no_small_buffer.data[buffer_size] = x;
				base.no_small_buffer.data[buffer_size + 1] = '\0';

				base.no_small_buffer.size = 16;
			}
			else
			{
				base.small_buffer.data[buffer_size] = x;
				base.small_buffer.data[buffer_size + 1] = '\0';
			}
		}
        else
        {
            if (cap == base.no_small_buffer.size)
            {
                this->reserve(base.no_small_buffer.size * 1.5);
            }

            base.no_small_buffer.data[base.no_small_buffer.size] = x;
            base.no_small_buffer.data[base.no_small_buffer.size + 1] = '\0';

            base.no_small_buffer.size++;
        }
	}

    void erase(int begin_pos, int len = -1)
    {
        if (len == -1)
        {
            len = this->size() - begin_pos;
        }

        string tmp;

        tmp.reserve(this->size());

        for (int i = 0; i <= this->size(); i++)
        {
            if (!(i >= begin_pos && i < begin_pos + len))
            {
                tmp.push_back(this->c_str()[i]);
            }
        }

        *this = tmp;
    }

    void insert(int pos, const string& str)
    {
        string tmp;

        tmp.reserve(this->size() + str.size());

        for (int i = 0; i < this->size() + str.size(); i++)
        {
            if (i >= pos && i < (pos + str.size()))
            {
                tmp.push_back(str[i - pos]);
            }
            else
            {
                if (i < pos)
                {
                    tmp.push_back(this->c_str()[i]);
                }
                else
                {
                    tmp.push_back(this->c_str()[i - str.size()]);
                }
            }
        }

        *this = tmp;
    }

    int count(const char& x)
    {
        int count = 0;

        for (int i = 0; i < this->size(); i++)
        {
            if (this->c_str()[i] == x)
            {
                count++;
            }
        }

        return count;
    }

    int find_first(const char& x)
    {
        for (int i = 0; i < this->size(); i++)
        {
            if (this->c_str()[i] == x)
            {
                return i;
            }
        }

        return -1;
    }

    char& operator[] (size_t i) 
    {
        if (cap == 15)
        {
            return base.small_buffer.data[i];
        }
        else
        {
            return base.no_small_buffer.data[i];
        }
    }

    const char& operator[] (size_t i) const
    {
        if (cap == 15)
        {
            return base.small_buffer.data[i];
        }
        else
        {
            return base.no_small_buffer.data[i];
        }
    }

	size_t capacity() const
	{
		return cap;
	}

	size_t size() const
	{
		if (cap == 15)
		{
			return tool::strlen(base.small_buffer.data);
		}
		else
		{
			return base.no_small_buffer.size;
		}
	}
};

std::ostream& operator << (std::ostream& out, const string& p)
{
	if (p.cap == 15)
	{
		return out << p.base.small_buffer.data;
	}
	else
	{
		return out << p.base.no_small_buffer.data;
	}
}

std::istream& operator >> (std::istream& in, string& s)
{
    s.~string();
    
    char tempchar;

    for (int i = 0; ; i++)
    {
        tempchar = getchar();

        if (tempchar == '\n')
        {
            break;
        }
        else
        {
            s.push_back(tempchar);
        }
    }

    return in;
}


/*int main()
{
    
    string tmp, r, t;
    t.push_back('g');
    r.push_back('f');

    tmp = t + r;

    std::cout << t;
}*/
