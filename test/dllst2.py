import os
import ctypes
import logging

# Initialisiere Logging
logging.basicConfig(level=logging.INFO, format="%(asctime)s [%(levelname)s] %(message)s")

# Absoluter Pfad zur DLL
dll_path = os.path.abspath(os.path.join(os.path.dirname(__file__), "../cmake-build-debug-visual-studio/bin/moo.dll"))

# DLL laden
try:
    math = ctypes.CDLL(dll_path)
    logging.info("DLL erfolgreich geladen ✅")
except OSError as e:
    logging.error(f"DLL konnte nicht geladen werden: {e}")
    exit(1)

# Funktionssignaturen setzen
math.permutation.restype = ctypes.POINTER(ctypes.c_int64)
math.permutation.argtypes = [ctypes.c_int64]

math.clearptr.restype = None
math.clearptr.argtypes = [ctypes.POINTER(ctypes.c_int64)]

math.genPerm.restype = ctypes.POINTER(ctypes.c_int64)
math.genPerm.argtypes = [ctypes.c_int64]

# Test: Fakultätstabelle
n = 5
ptr = math.permutation(n)
if not ptr:
    logging.error("Fehler: NULL-Pointer von permutation zurückgegeben.")
else:
    fakultaet = [ptr[i] for i in range(n + 1)]
    print(f"{n}! Tabelle =", fakultaet)
    math.clearptr(ptr)
    print("Speicher für Fakultät freigegeben.")

# Test: Alle Permutationen
ptr_perm = math.genPerm(n)
if not ptr_perm:
    logging.error("Fehler: NULL-Pointer von genPerm zurückgegeben.")
else:
    from math import factorial

    total = factorial(n)
    print(f"Alle {total} Permutationen von 0 bis {n-1}:")
    for i in range(total):
        start = i * n
        perm = [ptr_perm[start + j] for j in range(n)]
        print(f"{i + 1}: {perm}")

    math.clearptr(ptr_perm)
    print("Speicher für Permutationen freigegeben.")
