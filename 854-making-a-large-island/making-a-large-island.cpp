#include <vector>
#include <unordered_set>
#include <numeric>
#include <algorithm>

using namespace std;

class Solution {
private:
    int n;
    int dirs[5] = {-1, 0, 1, 0, -1};

    int dfs(int r, int c, int id, vector<vector<int>>& grid) {
        grid[r][c] = id;
        int size = 1;
        for (int i = 0; i < 4; ++i) {
            int nr = r + dirs[i], nc = c + dirs[i + 1];
            if (nr >= 0 && nr < n && nc >= 0 && nc < n && grid[nr][nc] == 1) {
                size += dfs(nr, nc, id, grid);
            }
        }
        return size;
    }

public:
    int largestIsland(vector<vector<int>>& grid) {
        n = grid.size();
        vector<int> island_sizes = {0, 0}; // Pad index 0 and 1
        int island_id = 2;
        int max_size = 0;

        // Step 1: Label components and record sizes
        for (int r = 0; r < n; ++r) {
            for (int c = 0; c < n; ++c) {
                if (grid[r][c] == 1) {
                    island_sizes.push_back(dfs(r, c, island_id, grid));
                    max_size = max(max_size, island_sizes.back());
                    island_id++;
                }
            }
        }

        // Step 2: Evaluate flipping each 0
        for (int r = 0; r < n; ++r) {
            for (int c = 0; c < n; ++c) {
                if (grid[r][c] == 0) {
                    unordered_set<int> neighbor_ids;
                    for (int i = 0; i < 4; ++i) {
                        int nr = r + dirs[i], nc = c + dirs[i + 1];
                        if (nr >= 0 && nr < n && nc >= 0 && nc < n && grid[nr][nc] > 1) {
                            neighbor_ids.insert(grid[nr][nc]);
                        }
                    }
                    
                    int current_possible = 1;
                    for (int id : neighbor_ids) {
                        current_possible += island_sizes[id];
                    }
                    max_size = max(max_size, current_possible);
                }
            }
        }

        return max_size;
    }
};