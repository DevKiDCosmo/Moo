import os
import ctypes
from sys import platform

class moo:
    def __init__(self, file="moo.dll"):
        """
        Initialize the moo class by loading the moo.dll file.
        This file should be located in the same directory as this script.
        """
        if file == "moo.dll":
            if platform == "linux" or platform == "linux2":
                file = "libMoo.so"
            elif platform == "darwin":
                file = "libMoo.dylib"
            else:
                file = "moo.dll"

        try:
            dll_path = os.path.abspath(os.path.join(os.path.dirname(__file__), f"./{file}"))
            self.moo = ctypes.CDLL(dll_path)
        except OSError as e:
            raise OSError(f"Could not load the shared object '{file}'. Ensure it exists in the same directory as this script. Error: {e}")

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

    def floor(self, a: float) -> int:
        """
        Calculate the floor division of two numbers.
        :param a: Dividend.
        :param b: Divisor.
        :return: Result of floor division.
        """
        self.moo.dfloor.restype = ctypes.c_int64
        self.moo.dfloor.argtypes = [ctypes.c_double]
        return self.moo.dfloor(ctypes.c_double(a))

    def ceil(self, a: float) -> int:
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
        return self.moo.fac(n)

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

    def combination(self, n: int, k: int) -> int:
        """
        Calculate the number of combination of n items taken k at a time.
        :param n: Total number of items.
        :param k: Number of items to choose.
        :return: Number of combination.
        """
        self.moo.combination.restype = ctypes.c_int64
        self.moo.combination.argtypes = [ctypes.c_int, ctypes.c_int]
        return self.moo.combination(ctypes.c_int(n), ctypes.c_int(k))

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

        self.moo.freeptr.restype = None
        self.moo.freeptr.argtypes = [ctypes.POINTER(ctypes.c_int64)]
        self.moo.freeptr(ptr_perm)

        return result

    def max(self, a: float, b: float) -> float:
        """
        Calculate the maximum of two numbers.
        :param a: First number.
        :param b: Second number.
        :return: Maximum of the two numbers.
        """
        self.moo.max.restype = ctypes.c_double
        self.moo.max.argtypes = [ctypes.c_double, ctypes.c_double]
        return self.moo.max(ctypes.c_double(a), ctypes.c_double(b))

    def min(self, a: float, b: float) -> float:
        """
        Calculate the minimum of two numbers.
        :param a: First number.
        :param b: Second number.
        :return: Minimum of the two numbers.
        """
        self.moo.min.restype = ctypes.c_double
        self.moo.min.argtypes = [ctypes.c_double, ctypes.c_double]
        return self.moo.min(ctypes.c_double(a), ctypes.c_double(b))

    def pow(self, x: float, b: int) -> float:
        """
        Calculate the power of a number.
        :param x: Base number.
        :param b: Exponent.
        :return: Result of x raised to the power of b.
        """
        self.moo.dpow.restype = ctypes.c_double
        self.moo.dpow.argtypes = [ctypes.c_double, ctypes.c_int]
        return self.moo.dpow(ctypes.c_double(x), ctypes.c_int(b))

    def fpow(self, x: float, b: float) -> float:
        """
        Calculate the floating-point power of a number.
        :param x: Base number.
        :param b: Exponent.
        :return: Result of x raised to the power of b.
        """
        self.moo.fpow.restype = ctypes.c_double
        self.moo.fpow.argtypes = [ctypes.c_double, ctypes.c_double]
        return self.moo.fpow(ctypes.c_double(x), ctypes.c_double(b))

    def log(self, x: float, base: float = 10.0) -> float:
        """
        Calculate the logarithm of a number with a specified base.
        :param x: Number to calculate the logarithm of.
        :param base: Base of the logarithm (default is 10).
        :return: Logarithm of the number with the specified base.
        """
        self.moo.dlog.restype = ctypes.c_double
        self.moo.dlog.argtypes = [ctypes.c_double, ctypes.c_double]
        return self.moo.dlog(ctypes.c_double(x), ctypes.c_double(base))

    def ln(self, x: float) -> float:
        """
        Calculate the natural logarithm of a number.
        :param x: Number to calculate the natural logarithm of.
        :return: Natural logarithm of the number.
        """
        self.moo.ln.restype = ctypes.c_double
        self.moo.ln.argtypes = [ctypes.c_double]
        return self.moo.ln(ctypes.c_double(x))

    def exp(self, x: float) -> float:
        """
        Calculate the exponential of a number.
        :param x: Number to calculate the exponential of.
        :return: Exponential of the number.
        """
        self.moo.dexp.restype = ctypes.c_double
        self.moo.dexp.argtypes = [ctypes.c_double]
        return self.moo.dexp(ctypes.c_double(x))

    def sqrt(self, x: float) -> float:
        """
        Calculate the square root of a number.
        :param x: Number to calculate the square root of.
        :return: Square root of the number.
        """
        self.moo.dsqrt.restype = ctypes.c_double
        self.moo.dsqrt.argtypes = [ctypes.c_double]
        return self.moo.dsqrt(ctypes.c_double(x))

    def ksqrt(self, x: float, k: float) -> float:
        """
        Calculate the k-th root of a number.
        :param x: Number to calculate the k-th root of.
        :param k: The degree of the root.
        :return: k-th root of the number.
        """
        self.moo.dksqrt.restype = ctypes.c_double
        self.moo.dksqrt.argtypes = [ctypes.c_double, ctypes.c_int]
        return self.moo.dksqrt(ctypes.c_double(x), ctypes.c_int(k))

    def round(self, x: float) -> float:
        """
        Round a number to a specified number of decimal places.
        :param x: Number to round.
        :param decimals: Number of decimal places to round to (default is 0).
        :return: Rounded number.
        """
        self.moo.round.restype = ctypes.c_double
        self.moo.round.argtypes = [ctypes.c_double]
        return self.moo.round(ctypes.c_double(x))

    def roundk(self, x: float, k: int) -> float:
        """
        Round a number to a specified number of decimal places.
        :param x: Number to round.
        :param k: Number of decimal places to round to.
        :return: Rounded number.
        """
        self.moo.roundk.restype = ctypes.c_double
        self.moo.roundk.argtypes = [ctypes.c_double, ctypes.c_int]
        return self.moo.roundk(ctypes.c_double(x), ctypes.c_int(k))

    def i(self):
        """
        Get the the nullptr as index for intervals.
        :return: Imaginary unit (i) for intervals.
        """
        return ctypes.c_void_p(0)

    def interval(self, start: int, end: int, step: int, argCount: int, function: str, vars) -> list:
        """
        Ruft die C-API-Funktion interval_c auf.
        :param start: Startwert des Intervalls.
        :param end: Endwert des Intervalls.
        :param step: Schrittweite.
        :param argCount: Anzahl der Argumente für die Funktion.
        :param function: Funktionszeiger (ctypes.CFUNCTYPE).
        :param vars: Zeiger auf Variablen (ctypes.POINTER(ctypes.POINTER(ctypes.c_int64))).
        :param out_count: Zeiger auf Ausgabewert (ctypes.POINTER(ctypes.c_int64)).
        :return: Liste der Ergebnisse.
        """

        # Construct vars to int64_t**
        if not isinstance(vars, ctypes.POINTER(ctypes.POINTER(ctypes.c_int64))):
            if isinstance(vars, list):
                vars = (ctypes.POINTER(ctypes.c_int64) * len(vars))(*[ctypes.pointer(ctypes.c_int64(v)) for v in vars])
            elif isinstance(vars, ctypes.POINTER(ctypes.c_int64)):
                vars = ctypes.pointer(vars)
            else:
                raise TypeError("vars must be a list or ctypes.POINTER(ctypes.POINTER(ctypes.c_int64)).")

        self.moo.interval_c.restype = ctypes.POINTER(ctypes.c_int64)
        self.moo.interval_c.argtypes = [
            ctypes.c_int64, ctypes.c_int64, ctypes.c_int64, ctypes.c_int64,
            ctypes.c_char_p,
            ctypes.POINTER(ctypes.POINTER(ctypes.c_int64)),
            ctypes.POINTER(ctypes.c_int64)
        ]

        ptr = self.moo.interval_c(
            ctypes.c_int64(start), ctypes.c_int64(end), ctypes.c_int64(step), ctypes.c_int64(argCount),
            function, vars
        )
        if not ptr:
            raise ValueError("NULL pointer returned from interval_c function.")
        result = [ptr[i] for i in range(len(ptr))]
        self.moo.freeptr.restype = None
        self.moo.freeptr.argtypes = [ctypes.POINTER(ctypes.c_int64)]
        self.moo.freeptr(ptr)
        return result

    def executefunc(self, name: str, params, param_count: int) -> float:
        """
        Führt eine Funktion mit Namen und Parametern aus.
        :param name: Funktionsname.
        :param params: Zeiger auf Parameter (ctypes.POINTER(ctypes.c_int64)).
        :param param_count: Anzahl der Parameter.
        :return: Ergebnis als float.
        """
        self.moo.executefunc.restype = ctypes.c_double
        self.moo.executefunc.argtypes = [ctypes.c_char_p, ctypes.POINTER(ctypes.c_int64), ctypes.c_int64]
        return self.moo.executefunc(name.encode('utf-8'), params, ctypes.c_int64(param_count))

    def executedfunc(self, id: int, result: float):
        """
        Übergibt das Ergebnis einer ausgeführten Funktion.
        :param id: Funktionsaufruf-ID.
        :param result: Ergebniswert.
        """
        self.moo.executedfunc.restype = None
        self.moo.executedfunc.argtypes = [ctypes.c_int64, ctypes.c_double]
        self.moo.executedfunc(ctypes.c_int64(id), ctypes.c_double(result))

    def execute_all_func_calls(self):
        """
        Liest alle Funktionsaufrufe aus und führt sie nativ aus.
        :return: Liste der Ergebnisse der Funktionsaufrufe.
        """
        self.moo.get_all_func_calls.restype = ctypes.POINTER(ctypes.c_void_p)
        self.moo.get_all_func_calls.argtypes = [ctypes.POINTER(ctypes.c_int64)]
        out_count = ctypes.c_int64()
        arr = self.moo.get_all_func_calls(ctypes.byref(out_count))
        if not arr:
            return []
        FUNC_CALL_C = ctypes.Structure
        FUNC_CALL_C._fields_ = [
            ('id', ctypes.c_int64),
            ('name', ctypes.c_char_p),
            ('params', ctypes.POINTER(ctypes.c_int64)),
            ('param_count', ctypes.c_int64)
        ]
        results = []
        for i in range(out_count.value):
            fc = ctypes.cast(arr[i], ctypes.POINTER(FUNC_CALL_C)).contents
            params = [fc.params[j] for j in range(fc.param_count)]
            func_name = fc.name.decode('utf-8')
            # Funktionszeiger holen und ausführen
            func = getattr(self.moo, func_name, None)
            if func is not None:
                # Annahme: alle Parameter sind int64 und Rückgabewert ist double
                func.restype = ctypes.c_double
                func.argtypes = [ctypes.c_int64] * fc.param_count
                result = func(*[ctypes.c_int64(p) for p in params])
                results.append({'id': fc.id, 'name': func_name, 'params': params, 'result': result})
            else:
                results.append({'id': fc.id, 'name': func_name, 'params': params, 'result': None})
        self.moo.free_func_calls.restype = None
        self.moo.free_func_calls.argtypes = [ctypes.POINTER(ctypes.c_void_p), ctypes.c_int64]
        self.moo.free_func_calls(arr, out_count)
        return results