#include "library.h"

// Platform-specific includes and initialization
#ifdef _WIN32
  #include <windows.h>
  #include <iostream>

  BOOL APIENTRY DllMain(
      HMODULE hModule,           // Handle to DLL module
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
#elif defined(__unix__) || defined(__APPLE__)
  // Unix-based systems initialization (if needed)
  // Currently no special initialization required
  
  // Library constructor/destructor attributes for Unix systems
  __attribute__((constructor))
  static void library_init(void) {
      // Optional: Add initialization code for Unix systems
  }
  
  __attribute__((destructor))
  static void library_cleanup(void) {
      // Optional: Add cleanup code for Unix systems  
  }
#endif // Platform-specific code