import moo
import pandas as pd

test_cases = pd.read_csv("test.csv", delimiter=";").values.tolist()

def test_moo():
    passed = 0
    failed = 0
    for idx, (func_name, expected, args) in enumerate(test_cases, 1):
        func = getattr(moo, func_name, None)
        if not callable(func):
            print(f"[{idx}] ERROR: Function `{func_name}` not found.")
            failed += 1
            continue
        try:
            result = func(*args)
            if result == expected:
                print(f"[{idx}] Test `{func_name}{args}` OK: got={result}, expected={expected}")
                passed += 1
            else:
                print(f"[{idx}] Test `{func_name}{args}` FAILED: got={result}, expected={expected}")
                failed += 1
        except Exception as e:
            print(f"[{idx}] Test `{func_name}{args}` EXCEPTION: {e}")
            failed += 1
    print(f"\nResult: {passed} OK, {failed} failed, {len(test_cases)} total.")

if __name__ == "__main__":
    print("Run Unittests for moo...")
    test_moo()
    print("Unittest finished.")