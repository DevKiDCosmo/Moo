import os
import ctypes
import logging

logging.basicConfig(level=logging.INFO, format="%(asctime)s [%(levelname)s] %(message)s")

# Strukturdefinition für C-Schnittstelle
class PermResult(ctypes.Structure):
    _fields_ = [
        ("data", ctypes.POINTER(ctypes.c_int64)),
        ("count", ctypes.c_int64),
        ("length", ctypes.c_int64),
    ]

# DLL-Pfad
dll_path = os.path.abspath(
    os.path.join(os.path.dirname(__file__), "../cmake-build-debug-visual-studio/bin/moo.dll")
)

# DLL laden
math = ctypes.CDLL(dll_path)

# Signaturen definieren
math.genpermutation.restype = PermResult
math.genpermutation.argtypes = [ctypes.c_int]
math.fpermutation.restype = None
math.fpermutation.argtypes = [ctypes.POINTER(PermResult)]

# Permutationsdaten abrufen
n = 4
res = math.genpermutation(n)
if not bool(res.data):
    print("Fehler: NULL-Pointer von C++ zurückgegeben.")
else:
    print(f"Permutationen für n = {n}:")
    for i in range(res.count):
        perm = [res.data[i * res.length + j] for j in range(res.length)]
        print(perm)
    # Speicher in C++ freigeben
    math.fpermutation(ctypes.byref(res))
    print("Speicher erfolgreich freigegeben.")
print("Fertig.")