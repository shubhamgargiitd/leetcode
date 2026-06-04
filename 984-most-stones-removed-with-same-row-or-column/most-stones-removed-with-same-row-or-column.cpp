class DSU {
private:
    unordered_map<int, int> parent;

public:
    int components = 0;

    int find(int i) {
        // If 'i' is not in the map, it's a new element/component
        if (parent.find(i) == parent.end()) {
            parent[i] = i;
            components++;
        }
        if (parent[i] == i) return i;
        return parent[i] = find(parent[i]); // Path compression
    }

    void unionNodes(int i, int j) {
        int rootI = find(i);
        int rootJ = find(j);
        if (rootI != rootJ) {
            parent[rootI] = rootJ;
            components--; // Two components merged into one
        }
    }
};

class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        DSU dsu;
        
        for (const auto& stone : stones) {
            // ~stone[1] distinguishes column indices from row indices
            dsu.unionNodes(stone[0], ~stone[1]);
        }
        
        return stones.size() - dsu.components;
    }
};