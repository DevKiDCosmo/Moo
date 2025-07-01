import os
import unittest
import ctypes
import logging
import time
import csv
import ast

logging.basicConfig(level=logging.INFO, format="%(asctime)s [%(levelname)s] %(message)s")

test_results = []

# Mapping von Typnamen zu ctypes
CTYPE_MAP = {
    "int": ctypes.c_int,
    "double": ctypes.c_double,
    "float": ctypes.c_float,
    "uint8_t": ctypes.c_uint8,
    "uint32_t": ctypes.c_uint32,
    "uint64_t": ctypes.c_uint64,
    "int64_t": ctypes.c_longlong,
    "int32_t": ctypes.c_int,
    "int16_t": ctypes.c_short,
    "uint16_t": ctypes.c_ushort,
    # ggf. weitere Typen ergänzen
}

class TestMathDLL(unittest.TestCase):
    @classmethod
    def setUpClass(cls):
        dll_path = os.path.abspath(os.path.join(os.path.dirname(__file__), "../cmake-build-release-visual-studio/bin/MooMSVC.dll"))
        logging.info(f"Versuche DLL zu laden: {dll_path}")
        try:
            cls.math = ctypes.CDLL(dll_path)
            logging.info("DLL erfolgreich geladen. ✅")
        except Exception as e:
            logging.error(f"Fehler beim Laden der DLL: {e} ❌")
            raise

    def run_test(self, func, *args, expected):
        test_id = f"{func.__name__}{args}"
        start = time.time()
        try:
            result = func(*args)
            if isinstance(expected, float):
                self.assertAlmostEqual(result, expected, places=6)
            else:
                self.assertEqual(result, expected)
            emoji = "✅"
            status = "OK"
        except AssertionError:
            result = func(*args)
            emoji = "❌"
            status = "FAIL"
        end = time.time()
        duration = int((end - start) * 1000)
        logging.info(
            f"{emoji} | {test_id} | {func.__name__} | args={args} | erwartet={expected} | erhalten={result} | {status} | {duration}ms")
        test_results.append({
            "FUNCTION": func.__name__,
            "ARGS": str(args),
            "EXPECTED": expected,
            "RESULT": result,
            "STATUS": status,
            "DURATION_MS": duration
        })

    def test_from_csv(self):
        csv_path = os.path.join(os.path.dirname(__file__), "test.csv")
        logging.info(f"Lese Testfälle aus {csv_path}")
        with open(csv_path, newline='') as csvfile:
            reader = csv.DictReader(csvfile, delimiter=';')
            for row in reader:
                func_name = row['FUNCTION']
                expected = ast.literal_eval(row['RESULT'])
                args = ast.literal_eval(row['ARGS'])
                type_name = row.get('TYPE', 'long long')
                ctype = CTYPE_MAP.get(type_name, ctypes.c_longlong)
                func = getattr(self.math, func_name)
                # Setze Rückgabe- und Argumenttypen
                func.restype = ctype
                func.argtypes = [ctype] * len(args)
                self.run_test(func, *args, expected=expected)

def export_results():
    out_path = os.path.join(os.path.dirname(__file__), "test_results.csv")
    with open(out_path, "w", newline='') as csvfile:
        fieldnames = ["FUNCTION", "ARGS", "EXPECTED", "RESULT", "STATUS", "DURATION_MS"]
        writer = csv.DictWriter(csvfile, fieldnames=fieldnames, delimiter=';')
        writer.writeheader()
        for row in test_results:
            writer.writerow(row)
    logging.info(f"Testergebnisse exportiert nach {out_path}")

    total = len(test_results)
    passed = sum(1 for r in test_results if r["STATUS"] == "OK")
    failed = total - passed
    avg_duration = sum(r["DURATION_MS"] for r in test_results) / total if total > 0 else 0

    logging.info("📊 Test-Zusammenfassung:")
    logging.info(f"✅ Bestandene Tests: {passed}")
    logging.info(f"❌ Fehlgeschlagene Tests: {failed}")
    logging.info(f"🧮 Durchschnittliche Dauer: {avg_duration:.2f} ms")

if __name__ == "__main__":
    logging.info("Starte Unittests")
    unittest.main(exit=False)
    export_results()