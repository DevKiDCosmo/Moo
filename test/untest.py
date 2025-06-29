import os
import csv
import ast
import ctypes
import unittest

class TestMathDLL(unittest.TestCase):
    @classmethod
    def setUpClass(cls):
        dll_path = os.path.abspath(os.path.join(os.path.dirname(__file__), "../cmake-build-debug-visual-studio/bin/TheMathLib.dll"))
        cls.math = ctypes.CDLL(dll_path)

    def test_from_csv(self):
        csv_path = os.path.join(os.path.dirname(__file__), "test.csv")
        with open(csv_path, newline='') as csvfile:
            reader = csv.DictReader(csvfile, delimiter=';')
            for row in reader:
                func_name = row['FUNCTION']
                expected = int(row['RESULT'])
                args = ast.literal_eval(row['ARGS'])
                func = getattr(self.math, func_name)
                result = func(*args)
                self.assertEqual(result, expected, f"{func_name}({args}) != {expected}, sondern {result}")

if __name__ == "__main__":
    unittest.main()