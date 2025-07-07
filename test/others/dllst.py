import os
import ctypes
import logging

logging.basicConfig(level=logging.INFO, format="%(asctime)s [%(levelname)s] %(message)s")

# Absoluter Pfad zur DLL
dll_path = os.path.abspath(os.path.join(os.path.dirname(__file__), "../../cmake-build-debug-visual-studio/bin/moo.dll"))
logging.info(f"Versuche DLL zu laden: {dll_path}")
math = ctypes.CDLL(dll_path)
logging.info("DLL erfolgreich geladen. ✅")

# Signaturen der exportierten Funktionen setzen
# Annahme: roundk nimmt zwei Argumente (double, int) und gibt double zurück
math.roundk.argtypes = [ctypes.c_double, ctypes.c_int]
math.roundk.restype = ctypes.c_double

# Beispielaufruf
result = math.roundk(32313.14159, 2)
logging.info(f"Ergebnis von roundk(3.14159, 2): {result}")