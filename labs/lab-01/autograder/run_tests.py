import unittest
from gradescope_utils.autograder_utils.json_test_runner import JSONTestRunner
from pathlib import Path

def main() -> None:
    suite = unittest.defaultTestLoader.discover("tests")
    results_file = Path("/autograder/results/results.json")

    with results_file.open("w") as f:
        JSONTestRunner(visibility="visible", stream=f).run(suite)


if __name__ == "__main__":
    main()