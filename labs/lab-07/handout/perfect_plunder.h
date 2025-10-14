#pragma once
#include <vector>
#include <cassert>
#include <cstdint>

struct House {
    uint32_t money;
    House *left;
    House *right;

    explicit House(uint32_t money) : money(money), left(nullptr), right(nullptr) {
    }
};

struct CulDeSac {
    House *house;

    explicit CulDeSac(const std::vector<House *> &houses) {
        assert(!houses.empty());
        for (size_t i = 0; i < houses.size() - 1; ++i)
            houses[i]->right = houses[i + 1];
        for (size_t i = 1; i < houses.size(); ++i)
            houses[i]->left = houses[i - 1];
        houses.front()->left = houses.back();
        houses.back()->right = houses.front();
        house = houses.front();
    }
};

[[nodiscard]] uint32_t perfect_plunder(const CulDeSac &cul_de_sac);
