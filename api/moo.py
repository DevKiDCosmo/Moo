import os
import ctypes


class moo:
    def __init__(self, file="moo.dll"):
        """
        Initialize the moo class by loading the moo.dll file.
        This file should be located in the same directory as this script.
        """
        dll_path = os.path.abspath(os.path.join(os.path.dirname(__file__), f"./{file}"))
        self.moo = ctypes.CDLL(dll_path)

    def absolute(self, x):
        """
        Calculate the absolute value of a number.
        :param x: Number to calculate the absolute value of.
        :return: Absolute value of the number.
        """
        self.moo.absolute.restype = ctypes.c_double
        self.moo.absolute.argtypes = [ctypes.c_double]
        return self.moo.absolute(ctypes.c_double(x))

    def idiv(self, a, b):
        """
        Calculate the integer division of two numbers.
        :param a: Dividend.
        :param b: Divisor.
        :return: Result of integer division.
        """
        self.moo.idiv.restype = ctypes.c_int64
        self.moo.idiv.argtypes = [ctypes.c_double, ctypes.c_double]
        return self.moo.idiv(ctypes.c_double(a), ctypes.c_double(b))

    def floor(self, a, b):
        """
        Calculate the floor division of two numbers.
        :param a: Dividend.
        :param b: Divisor.
        :return: Result of floor division.
        """
        self.moo.floor.restype = ctypes.c_int64
        self.moo.floor.argtypes = [ctypes.c_double, ctypes.c_double]
        return self.moo.floor(ctypes.c_double(a), ctypes.c_double(b))