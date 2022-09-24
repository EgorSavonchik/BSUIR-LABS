#include <iostream>
#include "windows.h"

class __declspec(dllimport) string
{
private:
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
};


int main()
{
	HMODULE lib;

	lib = LoadLibrary(L"dynamicStr.dll");
	
	void (string::*pConstructor)();
	(FARPROC&)pConstructor = GetProcAddress(lib, "??0string@@QEAA@XZ");


	void (string:: * pDestructor)();
	(FARPROC&)pDestructor = GetProcAddress(lib, "??1string@@QEAA@XZ");

    char* obj = new char[sizeof(string)];
    string* str = (string*)obj;

    (str->*pConstructor)();

    (str->*pDestructor)();
}