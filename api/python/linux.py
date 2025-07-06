import ctypes
import os

# Lade die Shared Library
lib_path = os.path.join(os.path.dirname(__file__), "moo.so")
moo = ctypes.CDLL(lib_path)

# Funktionssignaturen festlegen (Beispiel)
moo.abs.argtypes = [ctypes.c_double]
moo.abs.restype = ctypes.c_double

# Weitere Funktionssignaturen entsprechend festlegen...

def test_moo():
    abs_value = moo.abs(-42.0)
    print(f"Absolute value of -42.0: {abs_value}")

    # Weitere Funktionsaufrufe analog...

if __name__ == "__main__":
    test_moo()