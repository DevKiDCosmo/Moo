import os
import ctypes
import logging

logging.basicConfig(level=logging.INFO, format="%(asctime)s [%(levelname)s] %(message)s")

dll_path = os.path.abspath(os.path.join(os.path.dirname(__file__), "../cmake-build-debug-visual-studio/bin/moo.dll"))
logging.info(f"Versuche DLL zu laden: {dll_path}")
math = ctypes.CDLL(dll_path)
logging.info("DLL erfolgreich geladen. ✅")

math.flmod.restype = ctypes.c_double
math.flmod.argtypes = [ctypes.c_double, ctypes.c_double]
result = math.flmod(24.3, 23.1)
print("=", result)