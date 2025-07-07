import os
import ctypes
import logging

logging.basicConfig(level=logging.INFO, format="%(asctime)s [%(levelname)s] %(message)s")

# Absoluter Pfad zur DLL
dll_path = os.path.abspath(os.path.join(os.path.dirname(__file__), "../cmake-buildinf-debug-visual-studio/bin/moo.dll"))
logging.info(f"Versuche DLL zu laden: {dll_path}")
math = ctypes.CDLL(dll_path)
logging.info("DLL erfolgreich geladen. ✅")

# Signaturen der exportierten Funktionen setzen
math.factable.restype = ctypes.POINTER(ctypes.c_int64)
math.factable.argtypes = [ctypes.c_int64]

math.clearptr.restype = None
math.clearptr.argtypes = [ctypes.POINTER(ctypes.c_int64)]

# Test
n = 5
ptr = math.factable(n)

if not ptr:
    print("Fehler: NULL-Pointer von C++ zurückgegeben.")
else:
    result = [ptr[i] for i in range(n + 1)]
    print(f"{n}! Tabelle =", result)

    # Speicher freigeben
    math.clearptr(ptr)
    print("Speicher erfolgreich freigegeben.")