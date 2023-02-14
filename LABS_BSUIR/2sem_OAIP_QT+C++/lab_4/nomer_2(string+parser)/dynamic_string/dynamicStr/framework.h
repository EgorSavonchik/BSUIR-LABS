#pragma once

#define WIN32_LEAN_AND_MEAN             // Исключите редко используемые компоненты из заголовков Windows
// Файлы заголовков Windows
#include <windows.h>

#ifdef DYNAMICSTR_EXPORTS
#define DYNAMICSTR __declspec(dllexport)
#else
#define DYNAMICSTR __declspec(dllimport)
#endif

void* memcpy(void* s1, const void* s2, size_t n);

void* memmove(void* s1, const void* s2, size_t n);

size_t strlen(const char* s);

char* strcpy(char* s1, const char* s2);

char* strncpy(char* s1, const char* s2, size_t n);

char* strcat(char* s1, const char* s2);

char* strncat(char* s1, const char* s2, size_t n);

int memcmp(const void* s1, const void* s2, size_t n);

int strcmp(const char* s1, const char* s2);

const char* strchr(const char* s, char c);

int strncmp(const char* s1, const char* s2, size_t n);

size_t strxfrm(char* s1, const char* s2, size_t n);

char* strtok(char* s1, char* s2);

void* memset(void* s, int c, size_t n);



class DYNAMICSTR string
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

public:

    string();

    ~string();

    string(const char* input);

    string(string& input);

    string& operator= (const char* input);

    string operator+=(const char& ch);

    string& operator= (string& input);

    string& operator= (string&& input);

    string operator+ (const string& input);

    string operator+=(const string& input);

    string operator+ (const char* input);

    string operator+=(const char* input);

    bool operator==(const string& input) const;

    bool operator==(const char* input) const;

    void resize(size_t newLen, char agg = ' ');

    bool operator<(const string& str);

    bool operator>(const string& str);

    void reserve(size_t n);

    const char* c_str() const;

    void push_back(const char& x);

    void erase(int begin_pos, int len = -1);

    void insert(int pos, const string& str);

    int count(const char& x);

    int find_first(const char& x);

    char& operator[] (size_t i);

    const char& operator[] (size_t i) const;

    size_t capacity() const;

    size_t size() const;
};
