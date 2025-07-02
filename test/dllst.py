import os
import ctypes
import logging

logging.basicConfig(level=logging.INFO, format="%(asctime)s [%(levelname)s] %(message)s")

# Absoluter Pfad zur DLL
dll_path = os.path.abspath(os.path.join(os.path.dirname(__file__), "../cmake-build-debug-visual-studio/bin/moo.dll"))
logging.info(f"Versuche DLL zu laden: {dll_path}")
math = ctypes.CDLL(dll_path)
logging.info("DLL erfolgreich geladen. ✅")

# Signaturen der exportierten Funktionen setzen
math.permutation.restype = ctypes.POINTER(ctypes.c_int64)
math.permutation.argtypes = [ctypes.c_int64]

math.fpermutation.restype = None
math.fpermutation.argtypes = [ctypes.POINTER(ctypes.c_int64)]

# Test
n = 20
ptr = math.permutation(n)

if not ptr:
    print("Fehler: NULL-Pointer von C++ zurückgegeben.")
else:
    result = [ptr[i] for i in range(n + 1)]
    print(f"{n}! Tabelle =", result)

    # Speicher freigeben
    math.fpermutation(ptr)
    print("Speicher erfolgreich freigegeben.")

