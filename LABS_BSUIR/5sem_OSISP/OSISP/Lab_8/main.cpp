#include <iostream>
#define _WIN32_DCOM
#include <windows.h>
#include <Wbemidl.h>
#include <comdef.h>
#include <string>
#include <locale>

# pragma comment(lib, "wbemuuid.lib")

bool initializeCom() {

    HRESULT hres = CoInitializeEx(0, COINIT_MULTITHREADED);
    if (FAILED(hres))
    {
        std::cout << "Failed to initialize COM library. Error code = 0x"
            << std::hex << hres << std::endl;
        return false;
    }

    hres = CoInitializeSecurity(
        nullptr,
        -1,
        nullptr,
        nullptr,
        RPC_C_AUTHN_LEVEL_DEFAULT,
        RPC_C_IMP_LEVEL_IMPERSONATE,
        nullptr,
        EOAC_NONE,
        nullptr
    );

    if (FAILED(hres))
    {
        std::cout << "Failed to initialize security. Error code = 0x"
            << std::hex << hres << std::endl;
        CoUninitialize();
        return false;
    }
    return true;
}

bool setUpWBEM(IWbemLocator*& wbemLocator, IWbemServices*& wbemServices) {
    HRESULT hres = CoCreateInstance(
        CLSID_WbemLocator,
        0,
        CLSCTX_INPROC_SERVER,
        IID_IWbemLocator, (LPVOID*)&wbemLocator);

    if (FAILED(hres))
    {
        std::cout << "Failed to create IWbemLocator object."
            << " Err code = 0x"
            << std::hex << hres << std::endl;
        CoUninitialize();
        return false;
    }

    // Step 4: -----------------------------------------------------
    // Connect to WMI through the IWbemLocator::ConnectServer method

    // Connect to the root\cimv2 namespace with
    // the current user and obtain pointer wbemServices
    // to make IWbemServices calls.

    hres = wbemLocator->ConnectServer(
        _bstr_t(L"ROOT\\CIMV2"),
        nullptr,
        nullptr,
        0,
        0,
        0,
        0,
        &wbemServices
    );

    if (FAILED(hres))
    {
        std::cout << "Could not connect. Error code = 0x" << std::hex << hres << std::endl;
        wbemLocator->Release();
        CoUninitialize();
        return false;
    }

    //std::cout << "Connected to ROOT\\CIMV2 WMI namespace" << std::endl;

    hres = CoSetProxyBlanket(
        wbemServices,
        RPC_C_AUTHN_WINNT,
        RPC_C_AUTHZ_NONE,
        nullptr,
        RPC_C_AUTHN_LEVEL_CALL,
        RPC_C_IMP_LEVEL_IMPERSONATE,
        nullptr,
        EOAC_NONE
    );

    if (FAILED(hres))
    {
        std::cout << "Could not set proxy blanket. Error code = 0x"
            << std::hex << hres << std::endl;
        wbemServices->Release();
        wbemLocator->Release();
        CoUninitialize();
        return false;
    }

    return true;
}

std::wstring get_os_name() {
    IWbemLocator* wbemLocator{ nullptr };
    IWbemServices* wbemServices{ nullptr };
    std::wstring ret;

    try {
        if (!initializeCom())
            throw "initializeCom failed";

        if (!setUpWBEM(wbemLocator, wbemServices))
            throw "setUpWBEM failed";

        BSTR bstr_wql = SysAllocString(L"WQL");
        BSTR bstr_sql = SysAllocString(L"SELECT * FROM Win32_OperatingSystem");

        IEnumWbemClassObject* pEnumerator{ nullptr };
        HRESULT hres = wbemServices->ExecQuery(
            bstr_wql,
            bstr_sql,
            WBEM_FLAG_FORWARD_ONLY | WBEM_FLAG_RETURN_IMMEDIATELY,
            nullptr,
            &pEnumerator);

        if (FAILED(hres))
        {
            std::cout << "Query for operating system name failed."
                << " Error code = 0x"
                << std::hex << hres << std::endl;
            wbemServices->Release();
            wbemLocator->Release();
            CoUninitialize();
            throw "ExecQuery failed";
        }

        IWbemClassObject* pclsObj{ nullptr };
        ULONG uReturn = 0;


        while (pEnumerator)
        {
            HRESULT hr = pEnumerator->Next(WBEM_INFINITE, 1,
                &pclsObj, &uReturn);

            if (0 == uReturn)
            {
                break;
            }

            VARIANT vtProp, vtProp1, vtProp2;

            hr = pclsObj->Get(L"Name", 0, &vtProp, 0, 0);
            HRESULT hr1 = pclsObj->Get(L"OSArchitecture", 0, &vtProp1, 0, 0);
            HRESULT hr2 = pclsObj->Get(L"BuildNumber", 0, &vtProp2, 0, 0);

            if (FAILED(hr))
                std::cout << "Failed to get name " << std::endl;
            if (FAILED(hr1))
                std::cout << "Failed to get name " << std::endl;
            if (FAILED(hr2))
                std::cout << "Failed to get name " << std::endl;

            //std::wcout << L" OS Name : " << vtProp.bstrVal << std::endl;

            //ret = std::wstring(L"OS Name: ");
            ret = std::wstring(vtProp.bstrVal);
            int pos = ret.find('|');
            ret.erase(ret.begin() + pos, ret.end());
            ret += L" " + std::wstring(vtProp1.bstrVal) + L" (Build " + std::wstring(vtProp2.bstrVal) + L")";

            VariantClear(&vtProp);
            VariantClear(&vtProp1);
            VariantClear(&vtProp2);

            pclsObj->Release();
        }

        wbemServices->Release();
        wbemLocator->Release();
        pEnumerator->Release();
        CoUninitialize();

    }
    catch (const std::string& error) {
        std::cout << error << std::endl;
    }

    return ret;
}

std::wstring get_user_name() {
    IWbemLocator* wbemLocator{ nullptr };
    IWbemServices* wbemServices{ nullptr };
    std::wstring ret;

    try {
        if (!initializeCom())
            throw "initializeCom failed";

        if (!setUpWBEM(wbemLocator, wbemServices))
            throw "setUpWBEM failed";

        BSTR bstr_wql = SysAllocString(L"WQL");
        BSTR bstr_sql = SysAllocString(L"SELECT * FROM Win32_ComputerSystem");

        IEnumWbemClassObject* pEnumerator{ nullptr };
        HRESULT hres = wbemServices->ExecQuery(
            bstr_wql,
            bstr_sql,
            WBEM_FLAG_FORWARD_ONLY | WBEM_FLAG_RETURN_IMMEDIATELY,
            nullptr,
            &pEnumerator);

        if (FAILED(hres))
        {
            std::cout << "Query for operating system name failed."
                << " Error code = 0x"
                << std::hex << hres << std::endl;
            wbemServices->Release();
            wbemLocator->Release();
            CoUninitialize();
            throw "ExecQuery failed";;
        }


        IWbemClassObject* pclsObj{ nullptr };
        ULONG uReturn = 0;

        while (pEnumerator)
        {
            HRESULT hr = pEnumerator->Next(WBEM_INFINITE, 1,
                &pclsObj, &uReturn);

            if (0 == uReturn)
            {
                break;
            }

            VARIANT vtProp;

            hr = pclsObj->Get(L"UserName", 0, &vtProp, 0, 0);

            if (FAILED(hr))
                std::cout << "Failed to get name " << std::endl;

            //std::wcout << L" OS Name : " << vtProp.bstrVal << std::endl;

            //ret = std::wstring(L"OS Name: ");
            ret = std::wstring(vtProp.bstrVal);
            int pos = ret.find('\\');
            ret.erase(ret.begin(), ret.begin() + pos + 1);

            VariantClear(&vtProp);

            pclsObj->Release();
        }

        wbemServices->Release();
        wbemLocator->Release();
        pEnumerator->Release();
        CoUninitialize();

    }
    catch (const std::string& error) {
        std::cout << error << std::endl;
    }

    return ret;
}

std::wstring get_computer_name() {
    IWbemLocator* wbemLocator{ nullptr };
    IWbemServices* wbemServices{ nullptr };
    std::wstring ret;

    try {
        if (!initializeCom())
            throw "initializeCom failed";

        if (!setUpWBEM(wbemLocator, wbemServices))
            throw "setUpWBEM failed";

        BSTR bstr_wql = SysAllocString(L"WQL");
        BSTR bstr_sql = SysAllocString(L"SELECT * FROM Win32_ComputerSystem");


        IEnumWbemClassObject* pEnumerator{ nullptr };
        HRESULT hres = wbemServices->ExecQuery(
            bstr_wql,
            bstr_sql,
            WBEM_FLAG_FORWARD_ONLY | WBEM_FLAG_RETURN_IMMEDIATELY,
            nullptr,
            &pEnumerator);

        if (FAILED(hres))
        {
            std::cout << "Query for operating system name failed."
                << " Error code = 0x"
                << std::hex << hres << std::endl;
            wbemServices->Release();
            wbemLocator->Release();
            CoUninitialize();
            throw "ExecQuery failed";
        }

        IWbemClassObject* pclsObj{ nullptr };
        ULONG uReturn = 0;

        while (pEnumerator)
        {
            HRESULT hr = pEnumerator->Next(WBEM_INFINITE, 1,
                &pclsObj, &uReturn);

            if (0 == uReturn)
            {
                break;
            }

            VARIANT vtProp;

            hr = pclsObj->Get(L"UserName", 0, &vtProp, 0, 0);

            if (FAILED(hr))
                std::cout << "Failed to get name " << std::endl;

            //std::wcout << L" OS Name : " << vtProp.bstrVal << std::endl;

            //ret = std::wstring(L"OS Name: ");
            ret = std::wstring(vtProp.bstrVal);
            int pos = ret.find('\\');
            ret.erase(ret.begin() + pos, ret.end());

            VariantClear(&vtProp);

            pclsObj->Release();
        }

        wbemServices->Release();
        wbemLocator->Release();
        pEnumerator->Release();
        CoUninitialize();

    }
    catch (const std::string& error) {
        std::cout << error << std::endl;
    }

    return ret;
}

std::wstring get_sys_man() {
    IWbemLocator* wbemLocator{ nullptr };
    IWbemServices* wbemServices{ nullptr };
    std::wstring ret;

    try {
        if (!initializeCom())
            throw "initializeCom failed";

        if (!setUpWBEM(wbemLocator, wbemServices))
            throw "setUpWBEM failed";

        BSTR bstr_wql = SysAllocString(L"WQL");
        BSTR bstr_sql = SysAllocString(L"SELECT * FROM Win32_ComputerSystem ");

        IEnumWbemClassObject* pEnumerator{ nullptr };
        HRESULT hres = wbemServices->ExecQuery(
            bstr_wql,
            bstr_sql,
            WBEM_FLAG_FORWARD_ONLY | WBEM_FLAG_RETURN_IMMEDIATELY,
            nullptr,
            &pEnumerator);

        if (FAILED(hres))
        {
            std::cout << "Query for operating system name failed."
                << " Error code = 0x"
                << std::hex << hres << std::endl;
            wbemServices->Release();
            wbemLocator->Release();
            CoUninitialize();
            throw "ExecQuery failed";
        }

        IWbemClassObject* pclsObj{ nullptr };
        ULONG uReturn = 0;

        while (pEnumerator)
        {
            HRESULT hr = pEnumerator->Next(WBEM_INFINITE, 1,
                &pclsObj, &uReturn);

            if (0 == uReturn)
            {
                break;
            }

            VARIANT vtProp;

            hr = pclsObj->Get(L"Manufacturer", 0, &vtProp, 0, 0);

            if (FAILED(hr))
                std::cout << "Failed to get name " << std::endl;

            //std::wcout << L" OS Name : " << vtProp.bstrVal << std::endl;

            //ret = std::wstring(L"OS Name: ");
            ret = std::wstring(vtProp.bstrVal);

            VariantClear(&vtProp);

            pclsObj->Release();
        }

        wbemServices->Release();
        wbemLocator->Release();
        pEnumerator->Release();
        CoUninitialize();

    }
    catch (const std::string& error) {
        std::cout << error << std::endl;
    }

    return ret;
}

std::wstring get_comp_model() {
    IWbemLocator* wbemLocator{ nullptr };
    IWbemServices* wbemServices{ nullptr };
    std::wstring ret;

    try {
        if (!initializeCom())
            throw "initializeCom failed";

        if (!setUpWBEM(wbemLocator, wbemServices))
            throw "setUpWBEM failed";


        BSTR bstr_wql = SysAllocString(L"WQL");
        BSTR bstr_sql = SysAllocString(L"SELECT * FROM Win32_ComputerSystem ");

        // For example, get the name of the operating system
        IEnumWbemClassObject* pEnumerator{ nullptr };
        HRESULT hres = wbemServices->ExecQuery(
            bstr_wql,
            bstr_sql,
            WBEM_FLAG_FORWARD_ONLY | WBEM_FLAG_RETURN_IMMEDIATELY,
            nullptr,
            &pEnumerator);

        if (FAILED(hres))
        {
            std::cout << "Query for operating system name failed."
                << " Error code = 0x"
                << std::hex << hres << std::endl;
            wbemServices->Release();
            wbemLocator->Release();
            CoUninitialize();
            throw "ExecQuery failed";
        }

        IWbemClassObject* pclsObj{ nullptr };
        ULONG uReturn = 0;

        while (pEnumerator)
        {
            HRESULT hr = pEnumerator->Next(WBEM_INFINITE, 1,
                &pclsObj, &uReturn);

            if (0 == uReturn)
            {
                break;
            }

            VARIANT vtProp;

            // Get the value of the Name property
            hr = pclsObj->Get(L"Model", 0, &vtProp, 0, 0);

            if (FAILED(hr))
                std::cout << "Failed to get name " << std::endl;

            //std::wcout << L" OS Name : " << vtProp.bstrVal << std::endl;

            //ret = std::wstring(L"OS Name: ");
            ret = std::wstring(vtProp.bstrVal);

            VariantClear(&vtProp);

            pclsObj->Release();
        }

        wbemServices->Release();
        wbemLocator->Release();
        pEnumerator->Release();
        CoUninitialize();

    }
    catch (const std::string& error) {
        std::cout << error << std::endl;
    }

    return ret;
}

std::wstring get_bios() {
    IWbemLocator* wbemLocator{ nullptr };
    IWbemServices* wbemServices{ nullptr };
    std::wstring ret;

    try {
        if (!initializeCom())
            throw "initializeCom failed";

        if (!setUpWBEM(wbemLocator, wbemServices))
            throw "setUpWBEM failed";

        BSTR bstr_wql = SysAllocString(L"WQL");
        BSTR bstr_sql = SysAllocString(L"SELECT * FROM Win32_BIOS ");

        // For example, get the name of the operating system
        IEnumWbemClassObject* pEnumerator{ nullptr };
        HRESULT hres = wbemServices->ExecQuery(
            bstr_wql,
            bstr_sql,
            WBEM_FLAG_FORWARD_ONLY | WBEM_FLAG_RETURN_IMMEDIATELY,
            nullptr,
            &pEnumerator);

        if (FAILED(hres))
        {
            std::cout << "Query for operating system name failed."
                << " Error code = 0x"
                << std::hex << hres << std::endl;
            wbemServices->Release();
            wbemLocator->Release();
            CoUninitialize();
            throw "ExecQuery failed";
        }

        IWbemClassObject* pclsObj{ nullptr };
        ULONG uReturn = 0;

        while (pEnumerator)
        {
            HRESULT hr = pEnumerator->Next(WBEM_INFINITE, 1,
                &pclsObj, &uReturn);

            if (0 == uReturn)
            {
                break;
            }

            VARIANT vtProp;

            hr = pclsObj->Get(L"BIOSVersion", 0, &vtProp, 0, 0);

            if (FAILED(hr))
                std::cout << "Failed to get name " << std::endl;

            //std::wcout << L" OS Name : " << vtProp.bstrVal << std::endl;

            //ret = std::wstring(L"OS Name: ");
            ret = std::wstring(vtProp.bstrVal);

            VariantClear(&vtProp);

            pclsObj->Release();
        }

        wbemServices->Release();
        wbemLocator->Release();
        pEnumerator->Release();
        CoUninitialize();

    }
    catch (const std::string& error) {
        std::cout << error << std::endl;
    }

    return ret;
}

std::wstring get_bios_ver() {
    HKEY hKey;

    std::wstring ret;

    const char* subKey = "HARDWARE\\DESCRIPTION\\System\\BIOS";


    LONG result = RegOpenKeyExA(HKEY_LOCAL_MACHINE, (LPCSTR)subKey, 0, KEY_READ | KEY_WOW64_64KEY, &hKey);

    if (result == ERROR_SUCCESS) {
        DWORD valueType;
        DWORD dataSize;
        BYTE* data = nullptr;
        const wchar_t* valueName = L"BIOSVersion";
        result = RegQueryValueEx(hKey, valueName, nullptr, &valueType, nullptr, &dataSize);

        if (result == ERROR_SUCCESS) {
            data = new BYTE[dataSize];
            if (RegQueryValueEx(hKey, valueName, nullptr, &valueType, data, &dataSize) == ERROR_SUCCESS) {
                if (valueType == REG_SZ) {
                    ret = std::wstring(reinterpret_cast<wchar_t*>(data));
                }
                else {
                    std::cout << "Unsupported data type." << std::endl;
                }
            }
            else {
                std::cerr << "Failed to query registry value." << std::endl;
            }
        }
        else {
            std::cerr << "Failed to get registry value size. Error code: " << result << std::endl;
        }

        RegCloseKey(hKey);
    }
    else {
        std::cerr << "Failed to open registry key. Error code: " << result << std::endl;
    }

    return ret;
}

std::wstring get_cpu() {
    IWbemLocator* wbemLocator{ nullptr };
    IWbemServices* wbemServices{ nullptr };
    std::wstring ret;

    try {
        if (!initializeCom())
            throw "initializeCom failed";

        if (!setUpWBEM(wbemLocator, wbemServices))
            throw "setUpWBEM failed";

        BSTR bstr_wql = SysAllocString(L"WQL");
        BSTR bstr_sql = SysAllocString(L"SELECT * FROM Win32_Processor ");

        IEnumWbemClassObject* pEnumerator{ nullptr };
        HRESULT hres = wbemServices->ExecQuery(
            bstr_wql,
            bstr_sql,
            WBEM_FLAG_FORWARD_ONLY | WBEM_FLAG_RETURN_IMMEDIATELY,
            nullptr,
            &pEnumerator);

        if (FAILED(hres))
        {
            std::cout << "Query for operating system name failed."
                << " Error code = 0x"
                << std::hex << hres << std::endl;
            wbemServices->Release();
            wbemLocator->Release();
            CoUninitialize();
            throw "ExecQuery failed";;
        }

        IWbemClassObject* pclsObj{ nullptr };
        ULONG uReturn = 0;

        while (pEnumerator)
        {
            HRESULT hr = pEnumerator->Next(WBEM_INFINITE, 1,
                &pclsObj, &uReturn), hr1, hr2, hr3;

            if (0 == uReturn)
            {
                break;
            }

            VARIANT vtProp, vtProp1, vtProp2, vtProp3;

            hr = pclsObj->Get(L"Name", 0, &vtProp, 0, 0);
            hr1 = pclsObj->Get(L"NumberOfCores", 0, &vtProp1, 0, 0);
            hr2 = pclsObj->Get(L"NumberOfLogicalProcessors", 0, &vtProp2, 0, 0);

            if (FAILED(hr))
                std::cout << "Failed to get name " << std::endl;
            if (FAILED(hr1))
                std::cout << "Failed to get name " << std::endl;
            if (FAILED(hr2))
                std::cout << "Failed to get name " << std::endl;

            //std::wcout << L" OS Name : " << vtProp.bstrVal << std::endl;

            //ret = std::wstring(L"OS Name: ");
            ret = std::wstring(vtProp.bstrVal) + L"(" + std::to_wstring(vtProp1.lVal) +
                L" Cores, " + std::to_wstring(vtProp2.lVal) + L" CPUs)";

            VariantClear(&vtProp);
            VariantClear(&vtProp1);
            VariantClear(&vtProp2);

            pclsObj->Release();
        }

        wbemServices->Release();
        wbemLocator->Release();
        pEnumerator->Release();
        CoUninitialize();

    }
    catch (const std::string& error) {
        std::cout << error << std::endl;
    }

    return ret;
}

std::wstring get_ram() {
    IWbemLocator* wbemLocator{ nullptr };
    IWbemServices* wbemServices{ nullptr };
    std::wstring ret;

    try {
        if (!initializeCom())
            throw "initializeCom failed";

        if (!setUpWBEM(wbemLocator, wbemServices))
            throw "setUpWBEM failed";


        BSTR bstr_wql = SysAllocString(L"WQL");
        BSTR bstr_sql = SysAllocString(L"SELECT * FROM Win32_ComputerSystem ");

        IEnumWbemClassObject* pEnumerator{ nullptr };
        HRESULT hres = wbemServices->ExecQuery(
            bstr_wql,
            bstr_sql,
            WBEM_FLAG_FORWARD_ONLY | WBEM_FLAG_RETURN_IMMEDIATELY,
            nullptr,
            &pEnumerator);

        if (FAILED(hres))
        {
            std::cout << "Query for operating system name failed."
                << " Error code = 0x"
                << std::hex << hres << std::endl;
            wbemServices->Release();
            wbemLocator->Release();
            CoUninitialize();
            throw "ExecQuery failed";
        }

        IWbemClassObject* pclsObj{ nullptr };
        ULONG uReturn = 0;

        while (pEnumerator)
        {
            HRESULT hr = pEnumerator->Next(WBEM_INFINITE, 1,
                &pclsObj, &uReturn);

            if (0 == uReturn)
            {
                break;
            }

            VARIANT vtProp;

            hr = pclsObj->Get(L"TotalPhysicalMemory", 0, &vtProp, 0, 0);

            if (FAILED(hr));
            unsigned long long totalMemoryBytes = _wtoi64(vtProp.bstrVal);
            //std::wcout << L" OS Name : " << vtProp.bstrVal << std::endl;
            int totalMemoryMB = static_cast<int>(totalMemoryBytes / (1024 * 1024));
            //ret = std::wstring(L"OS Name: ");
            ret.clear();
            auto tmp = vtProp.llVal;
            //std::wcout << L"Îáùåå êîëè÷åñòâî ïàìÿòè: " << totalMemoryMB << L" MB" << std::endl;

            ret = std::to_wstring(totalMemoryMB) + L" MB";
            //ret = tmp;

            VariantClear(&vtProp);

            pclsObj->Release();
        }


        wbemServices->Release();
        wbemLocator->Release();
        pEnumerator->Release();
        CoUninitialize();

    }
    catch (const std::string& error) {
        std::cout << error << std::endl;
    }

    return ret;
}

std::wstring get_gpu() {
    IWbemLocator* wbemLocator{ nullptr };
    IWbemServices* wbemServices{ nullptr };
    std::wstring ret;

    try {
        if (!initializeCom())
            throw "initializeCom failed";

        if (!setUpWBEM(wbemLocator, wbemServices))
            throw "setUpWBEM failed";

        BSTR bstr_wql = SysAllocString(L"WQL");
        BSTR bstr_sql = SysAllocString(L"SELECT * FROM Win32_VideoController ");

        // For example, get the name of the operating system
        IEnumWbemClassObject* pEnumerator{ nullptr };
        HRESULT hres = wbemServices->ExecQuery(
            bstr_wql,
            bstr_sql,
            WBEM_FLAG_FORWARD_ONLY | WBEM_FLAG_RETURN_IMMEDIATELY,
            nullptr,
            &pEnumerator);

        if (FAILED(hres))
        {
            std::cout << "Query for operating system name failed."
                << " Error code = 0x"
                << std::hex << hres << std::endl;
            wbemServices->Release();
            wbemLocator->Release();
            CoUninitialize();
            throw "ExecQuery failed";
        }

        IWbemClassObject* pclsObj{ nullptr };
        ULONG uReturn = 0;

        while (pEnumerator)
        {
            HRESULT hr = pEnumerator->Next(WBEM_INFINITE, 1,
                &pclsObj, &uReturn);

            if (0 == uReturn)
            {
                break;
            }

            VARIANT vtProp;

            hr = pclsObj->Get(L"Description", 0, &vtProp, 0, 0);

            if (FAILED(hr))
                std::cout << "Errors\n";
            //std::wcout << L"Îáùåå êîëè÷åñòâî ïàìÿòè: " << totalMemoryMB << L" MB" << std::endl;

            ret = std::wstring(vtProp.bstrVal);
            //ret = tmp;

            VariantClear(&vtProp);

            pclsObj->Release();
        }

        wbemServices->Release();
        wbemLocator->Release();
        pEnumerator->Release();
        CoUninitialize();

    }
    catch (const std::string& error) {
        std::cout << error << std::endl;
    }

    return ret;
}




int main() {
    std::wcout.imbue(std::locale("rus_rus.866"));
    std::wcin.imbue(std::locale("rus_rus.866"));

    std::wstring os_name = get_os_name();
    std::wstring user_name = get_user_name();
    std::wstring computer_name = get_computer_name();
    std::wstring sys_man = get_sys_man();
    std::wstring comp_model = get_comp_model();
    std::wstring bios = get_bios_ver();
    std::wstring cpu = get_cpu();
    std::wstring ram = get_ram();
    std::wstring gpu = get_gpu();

    std::wcout << "-------------DEVICE INFO-------------\n";
    std::wcout << L"OS Name: " << os_name << '\n';
    std::wcout << L"User Name: " << user_name << '\n';
    std::wcout << L"Computer Name: " << computer_name << '\n';
    std::wcout << L"Sustem Manyfacturer: " << sys_man << '\n';
    std::wcout << L"Computer Model: " << comp_model << '\n';
    std::wcout << L"BIOS: " << bios << '\n';
    std::wcout << L"CPU: " << cpu << '\n';
    std::wcout << L"RAM: " << ram << '\n';
    std::wcout << L"GPU(s): " << gpu << '\n';


    //while (true);

    return 0;
}
