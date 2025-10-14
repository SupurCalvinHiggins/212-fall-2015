#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "bug_bisect.h"
#include <vector>
#include <string>
#include <sstream>
#include <random>
#include <iomanip>

std::string to_hex(int num) {
    std::stringstream ss;
    ss << "0x" << std::uppercase << std::hex << num;
    return ss.str();
}

TestSuiteResult make_passing_suite(int id, int n_tests = 10) {
    std::vector<TestResult> results;
    results.reserve(n_tests);
    for (int i = 0; i < n_tests; ++i)
        results.emplace_back(i, i); // pass
    return {to_hex(id), std::move(results)};
}

TestSuiteResult make_failing_suite(int id, int n_tests = 10) {
    std::vector<TestResult> results;
    results.reserve(n_tests);
    for (int i = 0; i < n_tests; ++i)
        results.emplace_back(i, i + 1); // fail
    return {to_hex(id), std::move(results)};
}

TEST_CASE("bug_bisect - first suite fails") {
    std::vector<TestSuiteResult> suites = {
        make_failing_suite(0),
        make_passing_suite(1),
        make_passing_suite(2)
    };

    CHECK(bug_bisect(suites) == to_hex(0));
}

TEST_CASE("bug_bisect - last suite fails") {
    std::vector<TestSuiteResult> suites;
    for (int i = 0; i < 5; ++i)
        suites.push_back(make_passing_suite(i));
    suites.push_back(make_failing_suite(5));

    CHECK(bug_bisect(suites) == to_hex(5));
}

TEST_CASE("bug_bisect - middle suite fails") {
    std::vector<TestSuiteResult> suites;
    for (int i = 0; i < 3; ++i)
        suites.push_back(make_passing_suite(i));
    suites.push_back(make_failing_suite(3));
    for (int i = 4; i < 6; ++i)
        suites.push_back(make_failing_suite(i));

    CHECK(bug_bisect(suites) == to_hex(3));
}

TEST_CASE("bug_bisect - single failing suite") {
    std::vector<TestSuiteResult> suites = {make_failing_suite(0)};
    CHECK(bug_bisect(suites) == to_hex(0));
}

TEST_CASE("bug_bisect - large dataset") {
    const int total_commits = 10000;
    const int fail_index = 6789; // arbitrary fail position
    std::vector<TestSuiteResult> suites;
    suites.reserve(total_commits);

    for (int i = 0; i < total_commits; ++i) {
        if (i < fail_index)
            suites.push_back(make_passing_suite(i));
        else
            suites.push_back(make_failing_suite(i));
    }

    CHECK(bug_bisect(suites) == to_hex(fail_index));
}

TEST_CASE("bug_bisect - deterministic random fail positions") {
    const int total_commits = 2000;
    std::mt19937 rng(42); // fixed seed for reproducibility
    std::uniform_int_distribution<int> dist(0, total_commits - 1);

    for (int run = 0; run < 1000; ++run) {
        int fail_index = dist(rng);
        std::vector<TestSuiteResult> suites;
        suites.reserve(total_commits);

        for (int i = 0; i < total_commits; ++i) {
            if (i < fail_index)
                suites.push_back(make_passing_suite(i));
            else
                suites.push_back(make_failing_suite(i));
        }

        CHECK(bug_bisect(suites) == to_hex(fail_index));
    }
}
