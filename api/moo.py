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

    def abs(self, x):
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

    def floor(self, a: int) -> int:
        """
        Calculate the floor division of two numbers.
        :param a: Dividend.
        :param b: Divisor.
        :return: Result of floor division.
        """
        self.moo.dfloor.restype = ctypes.c_int64
        self.moo.dfloor.argtypes = [ctypes.c_double]
        return self.moo.dfloor(ctypes.c_double(a))

    def ceil(self, a: int) -> int:
        """
        Calculate the ceiling division of two numbers.
        :param a: Dividend.
        :param b: Divisor.
        :return: Result of ceiling division.
        """
        self.moo.dceil.restype = ctypes.c_int64
        self.moo.dceil.argtypes = [ctypes.c_double]
        return self.moo.dceil(ctypes.c_double(a))

    def gcd(self, a: int, b: int) -> int:
        """
        Calculate the greatest common divisor (GCD) of two numbers.
        :param a: First number.
        :param b: Second number.
        :return: GCD of the two numbers.
        """
        self.moo.gcd.restype = ctypes.c_int64
        self.moo.gcd.argtypes = [ctypes.c_int64, ctypes.c_int64]
        return self.moo.gcd(ctypes.c_int64(a), ctypes.c_int64(b))

    def lcm(self, a: int, b: int) -> int:
        """
        Calculate the least common multiple (LCM) of two numbers.
        :param a: First number.
        :param b: Second number.
        :return: LCM of the two numbers.
        """
        self.moo.lcm.restype = ctypes.c_int64
        self.moo.lcm.argtypes = [ctypes.c_int64, ctypes.c_int64]
        return self.moo.lcm(ctypes.c_int64(a), ctypes.c_int64(b))

    def mod(self, a: int, b: int) -> int:
        """
        Calculate the modulus of two numbers.
        :param a: Dividend.
        :param b: Divisor.
        :return: Result of modulus operation.
        """
        self.moo.mod.restype = ctypes.c_int64
        self.moo.mod.argtypes = [ctypes.c_int64, ctypes.c_int64]
        return self.moo.mod(ctypes.c_int64(a), ctypes.c_int64(b))

    def flmod(self, a: float, b: float) -> float:
        """
        Calculate the floating-point modulus of two numbers.
        :param a: Dividend.
        :param b: Divisor.
        :return: Result of floating-point modulus operation.
        """
        self.moo.flmod.restype = ctypes.c_double
        self.moo.flmod.argtypes = [ctypes.c_double, ctypes.c_double]
        return self.moo.flmod(ctypes.c_double(a), ctypes.c_double(b))

    def fac(self, n: int) -> int:
        """
        Calculate the factorial of a number.
        :param n: Number to calculate the factorial of.
        :return: Factorial of the number.
        """
        self.moo.fac.restype = ctypes.c_int64
        self.moo.fac.argtypes = [ctypes.c_int64]
        return self.moo.fac(ctypes.c_int(n))

    def binom(self, n: int, k: int) -> int:
        """
        Calculate the binomial coefficient (n choose k).
        :param n: Total number of items.
        :param k: Number of items to choose.
        :return: Binomial coefficient.
        """
        self.moo.binom.restype = ctypes.c_int64
        self.moo.binom.argtypes = [ctypes.c_int64, ctypes.c_int64]
        return self.moo.binom(ctypes.c_int64(n), ctypes.c_int64(k))

    def factable(self, n: int) -> list:
        """
        Generate a list of factorials from 0 to n.
        :param n: The number of elements to permute.
        :return: A list of the length of permutations.
        """
        if n <= 0:
            raise ValueError("n cannot be 0.")
        self.moo.factable.restype = ctypes.POINTER(ctypes.c_int64)
        self.moo.factable.argtypes = [ctypes.c_int64]

        ptr = self.moo.factable(n)
        if not ptr:
            raise ValueError("NULL pointer returned from factable function.")

        # Werte auslesen, bevor Speicher freigegeben wird
        result = [ptr[i] for i in range(n + 1)]

        self.moo.clearptr.restype = None
        self.moo.clearptr.argtypes = [ctypes.POINTER(ctypes.c_int64)]
        self.moo.clearptr(ptr)

        return result

    def permutation(self, n: int, k: int) -> int:
        """
        Calculate the number of permutations of n items taken k at a time.
        :param n: Total number of items.
        :param k: Number of items to choose.
        :return: Number of permutations.
        """
        self.moo.permutation.restype = ctypes.c_int64
        self.moo.permutation.argtypes = [ctypes.c_int, ctypes.c_int]
        return self.moo.permutation(ctypes.c_int(n), ctypes.c_int(k))

    def genPerm(self, n: int) -> list:
        """
        Generate all permutations of numbers from 0 to n-1.
        :param n: The number of elements to permute.
        :return: A list of all permutations.
        """
        if n <= 0:
            raise ValueError("n cannot be 0.")

        self.moo.genPerm.restype = ctypes.POINTER(ctypes.c_int64)
        self.moo.genPerm.argtypes = [ctypes.c_int64]
        ptr_perm = self.moo.genPerm(ctypes.c_int64(n))
        if not ptr_perm:
            raise ValueError("NULL pointer returned from genPerm function.")

        total = 1
        for i in range(1, n + 1):
            total *= i

        result = []
        for i in range(total):
            start = i * n
            perm = [ptr_perm[start + j] for j in range(n)]
            result.append(perm)

        self.moo.freePerm.restype = None
        self.moo.freePerm.argtypes = [ctypes.POINTER(ctypes.c_int64)]
        self.moo.freePerm(ptr_perm)

        return result

    def max(self, a: int, b: int) -> int:
        """
        Calculate the maximum of two numbers.
        :param a: First number.
        :param b: Second number.
        :return: Maximum of the two numbers.
        """
        self.moo.max.restype = ctypes.c_double
        self.moo.max.argtypes = [ctypes.c_double, ctypes.c_double]
        return self.moo.max(a, b)

    def min(self, a: int, b: int) -> int:
        """
        Calculate the minimum of two numbers.
        :param a: First number.
        :param b: Second number.
        :return: Minimum of the two numbers.
        """
        self.moo.min.restype = ctypes.c_double
        self.moo.min.argtypes = [ctypes.c_double, ctypes.c_double]
        return self.moo.min(a, b)
