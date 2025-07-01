import os
import ctypes
import logging

logging.basicConfig(level=logging.INFO, format="%(asctime)s [%(levelname)s] %(message)s")

dll_path = os.path.abspath(os.path.join(os.path.dirname(__file__), "../cmake-build-debug-visual-studio/bin/moo.dll"))
logging.info(f"Versuche DLL zu laden: {dll_path}")
math = ctypes.CDLL(dll_path)
logging.info("DLL erfolgreich geladen. ✅")

# Beispiel: Funktionsaufruf
math.absolute.restype = ctypes.c_longlong
math.absolute.argtypes = [ctypes.c_longlong]
result = math.absolute(-53)
print("absolute(-53) =", result)