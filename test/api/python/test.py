import os
import csv
import logging

logging.basicConfig(level=logging.INFO, format="%(asctime)s [%(levelname)s] %(message)s")

import ctypes

def to_native(val):
    if hasattr(val, "value"):
        return to_native(val.value)
    if isinstance(val, (list, tuple)):
        return [to_native(x) for x in val]
    if isinstance(val, ctypes._SimpleCData):
        return val.value
    return val


def run_test(moo, func_name, expected, args, idx):
    func = getattr(moo, func_name, None)
    test_id = f"{func_name}{args}"
    try:
        if not callable(func):
            raise AttributeError(f"Function `{func_name}` not found.")
        native_args = [to_native(a) for a in args]
        result = func(*native_args)
        result_list = result if isinstance(result, list) else [result]
        expected_list = expected if isinstance(expected, list) else [expected]
        def floats_equal(a, b):
            return abs(a - b) < 1e-6 if isinstance(a, float) and isinstance(b, float) else a == b
        ok = len(result_list) == len(expected_list) and all(floats_equal(r, e) for r, e in zip(result_list, expected_list))
        if ok:
            emoji = "✅"
            status = "OK"
        else:
            emoji = "❌"
            status = f"FAILED: got={result_list}, expected={expected_list}"
    except Exception as e:
        result_list = None
        expected_list = None
        emoji = "❌"
        status = f"EXCEPTION: {e}"
    logging.info(f"[{idx}] {emoji} {test_id} | args={args} | expected={expected_list} | got={result_list} | {status}")

if __name__ == "__main__":
    import moo

    logging.info("Run Unittest for moo...")
    object = moo.moo()

    csv_path = os.path.join(os.path.dirname(__file__), "test.csv")
    with open(csv_path, newline='', encoding="utf-8") as csvfile:
        reader = csv.reader(csvfile, delimiter=";")
        header = next(reader, None)
        for idx, (func_name, expected, args) in enumerate(reader, 1):
            expected_val = eval(expected)
            args_val = eval(args)
            if not isinstance(args_val, (list, tuple)):
                args_val = [args_val]
            run_test(object, func_name, expected_val, args_val, idx)

    logging.info("")
    logging.info("Unittest finished.")