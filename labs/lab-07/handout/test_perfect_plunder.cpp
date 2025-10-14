#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "perfect_plunder.h"
#include <vector>
#include <cstdint>
#include <algorithm>
#include <random>


CulDeSac make_cul_de_sac(const std::vector<uint32_t> &money_values) {
    std::vector<House *> houses;
    houses.reserve(money_values.size());
    for (const auto money: money_values)
        houses.push_back(new House(money));
    return CulDeSac(houses);
}

void free_cul_de_sac(CulDeSac &cul) {
    auto start = cul.house;
    auto current = start;
    do {
        const auto next = current->right;
        delete current;
        current = next;
    } while (current != start);
}

uint32_t linear_max_plunder(const std::vector<uint32_t> &houses) {
    if (houses.empty()) return 0;
    if (houses.size() == 1) return houses[0];

    uint32_t prev2 = 0;
    uint32_t prev1 = houses[0];
    for (size_t i = 1; i < houses.size(); ++i) {
        auto curr = std::max(prev1, prev2 + houses[i]);
        prev2 = prev1;
        prev1 = curr;
    }
    return prev1;
}

uint32_t circular_max_plunder(const std::vector<uint32_t> &houses) {
    if (houses.size() == 1) return houses[0];
    std::vector<uint32_t> without_first(houses.begin() + 1, houses.end());
    std::vector<uint32_t> without_last(houses.begin(), houses.end() - 1);
    return std::max(linear_max_plunder(without_first), linear_max_plunder(without_last));
}

// ------------------------------------------------------------
// Tests
// ------------------------------------------------------------

TEST_CASE("perfect_plunder - single house") {
    auto cul = make_cul_de_sac({100});
    CHECK(perfect_plunder(cul) == 100);
    free_cul_de_sac(cul);
}

TEST_CASE("perfect_plunder - two houses") {
    auto cul = make_cul_de_sac({100, 200});
    CHECK(perfect_plunder(cul) == 200);
    free_cul_de_sac(cul);
}

TEST_CASE("perfect_plunder - three houses") {
    auto cul = make_cul_de_sac({2, 3, 2});
    CHECK(perfect_plunder(cul) == 3);
    free_cul_de_sac(cul);
}

TEST_CASE("perfect_plunder - four houses") {
    auto cul = make_cul_de_sac({1, 2, 3, 1});
    CHECK(perfect_plunder(cul) == 4);
    free_cul_de_sac(cul);
}

TEST_CASE("perfect_plunder - deterministic") {
    std::vector<uint32_t> money;
    for (int i = 1; i <= 10; ++i) money.push_back(i % 100);
    auto cul = make_cul_de_sac(money);

    uint32_t expected = circular_max_plunder(money);
    CHECK(perfect_plunder(cul) == expected);
    free_cul_de_sac(cul);
}

TEST_CASE("perfect_plunder - random small tests") {
    std::mt19937 rng(12345);
    std::uniform_int_distribution<uint32_t> dist(1, 1000);

    for (int run = 0; run < 1000; ++run) {
        std::vector<uint32_t> money(10);
        for (auto &m: money) m = dist(rng);

        auto cul = make_cul_de_sac(money);
        uint32_t expected = circular_max_plunder(money);

        CHECK(perfect_plunder(cul) == expected);
        free_cul_de_sac(cul);
    }
}
