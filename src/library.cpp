#include "library.h"

#if defined(_WIN32) || defined(_WIN64)
#include <windows.h>
#else
#include <dlfcn.h>
#endif
#include <iostream>

BOOL APIENTRY DllMain(
    HANDLE hModule,            // Handle to DLL module
    DWORD  ul_reason_for_call, // Reason for calling function
    LPVOID lpReserved)         // Reserved
{
    switch (ul_reason_for_call) {
        case DLL_PROCESS_ATTACH: // A process is loading the DLL.
            std::cout << "DLL_PROCESS_ATTACH" << std::endl;
            std::cout << "DLL loaded at address: " << hModule << std::endl;
            std::cout << "Moo v1.0.0B" << std::endl;
            break;
        case DLL_THREAD_ATTACH: // A process is creating a new thread.
            std::cout << "DLL_THREAD_ATTACH" << std::endl;
            break;
        case DLL_THREAD_DETACH: // A thread exits normally.
            std::cout << "DLL_THREAD_DETACH" << std::endl;
            break;
        case DLL_PROCESS_DETACH: // A process unloads the DLL.
            std::cout << "DLL_PROCESS_DETACH" << std::endl;
            std::cout << "Moo v1.0.0B unloaded" << std::endl;
            break;
    }
    return TRUE;
}