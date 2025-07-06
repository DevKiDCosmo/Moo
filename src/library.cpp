#include "library.h"

#ifdef _WIN32
#include <windows.h>
#include <iostream>

BOOL APIENTRY DllMain(
    HANDLE hModule,
    DWORD  ul_reason_for_call,
    LPVOID lpReserved)
{
    switch (ul_reason_for_call) {
        case DLL_PROCESS_ATTACH:
            std::cout << "DLL_PROCESS_ATTACH" << std::endl;
            std::cout << "DLL loaded at address: " << hModule << std::endl;
            std::cout << "Moo v1.0.0B" << std::endl;
            break;
        case DLL_THREAD_ATTACH:
            std::cout << "DLL_THREAD_ATTACH" << std::endl;
            break;
        case DLL_THREAD_DETACH:
            std::cout << "DLL_THREAD_DETACH" << std::endl;
            break;
        case DLL_PROCESS_DETACH:
            std::cout << "DLL_PROCESS_DETACH" << std::endl;
            std::cout << "Moo v1.0.0B unloaded" << std::endl;
            break;
    }
    return TRUE;
}
#endif
