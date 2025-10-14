#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "roaming_roomba.h"
#include "doctest.h"
#include <vector>
#include <queue>
#include <random>
#include <algorithm>
#include <cstdint>
#include <cassert>

using Grid = std::vector<std::vector<Cell> >;
using Position = std::pair<int, int>;

Grid generate_room(int rows, int cols, double dirty_prob = 0.3, std::mt19937 &rng = std::mt19937(42)) {
    assert(rows >= 3 && cols >= 3);
    Grid grid(rows, std::vector<Cell>(cols, Cell::Wall));

    std::uniform_int_distribution<int> dist_r(1, rows - 2);
    std::uniform_int_distribution<int> dist_c(1, cols - 2);
    Position home{dist_r(rng), dist_c(rng)};
    grid[home.first][home.second] = Cell::Home;

    std::queue<Position> q;
    q.push(home);
    std::vector<std::vector<bool> > visited(rows, std::vector<bool>(cols, false));
    visited[home.first][home.second] = true;

    const std::vector<Position> dirs{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    while (!q.empty()) {
        auto [r,c] = q.front();
        q.pop();

        std::vector<Position> neighbors;
        for (auto [dr,dc]: dirs) {
            int nr = r + dr;
            int nc = c + dc;
            if (nr <= 0 || nr >= rows - 1 || nc <= 0 || nc >= cols - 1) continue;
            if (!visited[nr][nc]) neighbors.push_back({nr, nc});
        }

        std::shuffle(neighbors.begin(), neighbors.end(), rng);
        for (auto [nr,nc]: neighbors) {
            visited[nr][nc] = true;
            grid[nr][nc] = Cell::Clean;
            q.push({nr, nc});
        }
    }

    std::uniform_real_distribution<double> prob(0.0, 1.0);
    for (int r = 1; r < rows - 1; ++r) {
        for (int c = 1; c < cols - 1; ++c) {
            if (grid[r][c] == Cell::Clean && prob(rng) < dirty_prob) {
                grid[r][c] = Cell::Dirty;
            }
        }
    }

    return grid;
}

int bfs_distance(const Grid &grid, Position start, Position target) {
    const int R = grid.size();
    const int C = grid[0].size();
    std::queue<Position> q;
    std::vector<std::vector<int> > dist(R, std::vector<int>(C, -1));

    q.push(start);
    dist[start.first][start.second] = 0;

    const std::vector<Position> dirs{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    while (!q.empty()) {
        auto [r,c] = q.front();
        q.pop();
        if (r == target.first && c == target.second) return dist[r][c];

        for (auto [dr,dc]: dirs) {
            int nr = r + dr;
            int nc = c + dc;
            if (nr <= 0 || nr >= R - 1 || nc <= 0 || nc >= C - 1) continue;
            if (grid[nr][nc] == Cell::Wall) continue;
            if (dist[nr][nc] != -1) continue;

            dist[nr][nc] = dist[r][c] + 1;
            q.push({nr, nc});
        }
    }
    assert(false);
}


int compute_baseline_battery(const Grid &grid) {
    Position home{-1, -1};
    for (int r = 0; r < (int) grid.size(); ++r)
        for (int c = 0; c < (int) grid[0].size(); ++c)
            if (grid[r][c] == Cell::Home) home = {r, c};

    assert(home.first != -1);

    int max_battery = 0;
    for (int r = 0; r < (int) grid.size(); ++r) {
        for (int c = 0; c < (int) grid[0].size(); ++c) {
            if (grid[r][c] != Cell::Dirty) continue;
            int distance = bfs_distance(grid, home, {r, c});
            int battery = distance + 3 + (distance - 1);
            max_battery = std::max(max_battery, battery);
        }
    }
    return max_battery;
}

TEST_CASE("roaming_roomba - random reachable rooms") {
    std::mt19937 rng(12345);
    const int num_tests = 1000;
    const int rows = 10, cols = 10;

    for (int t = 0; t < num_tests; ++t) {
        auto room = generate_room(rows, cols, 0.3, rng);
        int baseline = compute_baseline_battery(room);
        int actual = roaming_roomba(room);

        CHECK(actual == baseline);
    }
}
