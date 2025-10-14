#pragma once
#include <vector>
#include <algorithm>
#include <string>

struct TestResult {
    int expected_output;
    int actual_output;

    TestResult(int expected_output, int actual_output) : expected_output(expected_output), actual_output(actual_output) { }

    [[nodiscard]] bool is_pass() const { return expected_output == actual_output; }
};

struct TestSuiteResult {
    std::string commit_id;
    std::vector<TestResult> results;

    TestSuiteResult(std::string&& commit_id, std::vector<TestResult>&& results) : commit_id(commit_id), results(results) { }

    [[nodiscard]] bool is_pass() const {
        return std::all_of(results.begin(), results.end(),[](const TestResult& result) -> bool { return result.is_pass(); });
    }
};

[[nodiscard]] std::string bug_bisect(const std::vector<TestSuiteResult>& suite_results);
