#pragma once
#include <vector>
#include <cstdint>

enum class Base {
    Adenine, Cytosine, Guanine, Thymine
};

[[nodiscard]] uint32_t genetic_gap(const std::vector<Base> &dna1, const std::vector<Base> &dna2);
