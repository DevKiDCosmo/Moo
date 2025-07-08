import ctypes

import moo

v = moo.moo()

def test_func(a, b):
    return a + b

k = [v.i(), 3]

print(v.interval(1, 24, 1, 2, "test_func", k))