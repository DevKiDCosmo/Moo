import moo
import csv

with open("test.csv", newline="", encoding="utf-8") as csvfile:
    reader = csv.reader(csvfile, delimiter=";")
    test_cases = list(reader)

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
            expected_val = eval(expected)
            args_val = eval(args)
            if not isinstance(args_val, (list, tuple)):
                args_val = [args_val]
            result = func(*args_val)
            if result == expected_val:
                print(f"[{idx}] Test `{func_name}{args_val}` OK: got={result}, expected={expected_val}")
                passed += 1
            else:
                print(f"[{idx}] Test `{func_name}{args_val}` FAILED: got={result}, expected={expected_val}")
                failed += 1
        except Exception as e:
            print(f"[{idx}] Test `{func_name}{args}` EXCEPTION: {e}")
            failed += 1
    print(f"\nResult: {passed} OK, {failed} failed, {len(test_cases)} total.")

if __name__ == "__main__":
    print("Run Unittests for moo...")
    test_moo()
    print("Unittest finished.")