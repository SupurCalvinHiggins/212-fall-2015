#include <iostream>
#include <vector>
#include <chrono>
#include "three_sum.h"
#include "three_sum_fast.h"

int main(const int argc, const char *argv[]) {
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <n>\n";
        return 1;
    }

    const auto n = std::stoi(argv[1]);
    if (n <= 0) {
        std::cerr << "n must be a positive integer\n";
        return 1;
    }

    std::vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        arr[i] = i;
    }
    const auto target = 3 * n;

    const auto start1 = std::chrono::high_resolution_clock::now();
    const auto result1 = three_sum(arr, target);
    const auto end1 = std::chrono::high_resolution_clock::now();
    const std::chrono::duration<double, std::milli> duration1 = end1 - start1;

    std::cout << "three_sum result: " << result1
            << ", time: " << duration1.count() << " ms\n";

    const auto start2 = std::chrono::high_resolution_clock::now();
    const auto result2 = three_sum_fast(arr, target);
    const auto end2 = std::chrono::high_resolution_clock::now();
    const std::chrono::duration<double, std::milli> duration2 = end2 - start2;

    std::cout << "three_sum_fast result: " << result2
            << ", time: " << duration2.count() << " ms\n";

    return 0;
}
