import moo


# Create test script to verify the functionality of the moo module
def test_moo():
    math = moo.moo()

    # Test absolute value
    abs_value = math.abs(-42.0)
    print(f"Absolute value of -42.0: {abs_value}")

    # Test integer division
    idiv_result = math.idiv(10, 3)
    print(f"Integer division of 10 by 3: {idiv_result}")

    # Test floor division
    floor_result = math.floor(10.323)
    print(f"Floor for 10.323: {floor_result}")

    # Test ceiling division
    ceil_result = math.ceil(10.43)
    print(f"Ceiling for 10.43: {ceil_result}")

    # Test GCD
    gcd_result = math.gcd(48, 18)
    print(f"GCD of 48 and 18: {gcd_result}")

    # Test LCM
    lcm_result = math.lcm(4, 6)
    print(f"LCM of 4 and 6: {lcm_result}")

    print(math.permutation(5, 3))

    n = 3
    ptr = math.factable(n)
    if not ptr:
        print("Error: NULL pointer returned from permutation.")
    else:
        fakultaet = [ptr[i] for i in range(n + 1)]
        print(f"{n}! table =", fakultaet)

    # Test generating permutations
    ptr_perm = math.genPerm(n)
    if not ptr_perm:
        print("Error: NULL pointer returned from genPerm.")
    else:
        for k in ptr_perm:
            print(k)

    print(math.min(10, 3))
    print(math.max(10, 3))

    print(math.combination(10, 5))
    print(math.permutation(10, 5))
    print(math.log(2493.0, 1.23))
    print(math.ln(3294.2))
    print(math.exp(2.71828))
    print(math.pow(4, 2))
    print(math.fpow(24.4, 3.32))


if __name__ == "__main__":
    test_moo()
