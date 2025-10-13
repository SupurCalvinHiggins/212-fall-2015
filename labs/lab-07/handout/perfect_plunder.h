#pragma once

struct House {
    int money;
    House* left;
    House* right;

    explicit House(int money) : money(money), left(nullptr), right(nullptr) { }
    House(int money, House* left, House* right) : money(money), left(left), right(right) { }
};

struct CulDeSac {
    House* first;

    explicit CulDeSac(House* first) : first(first) { }
};

[[nodiscard]] int perfect_plunder(const CulDeSac& cul_de_sac);