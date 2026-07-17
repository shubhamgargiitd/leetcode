class DSU {
public:
    vector<int> parent, rank;

    DSU(int n) : parent(n), rank(n, 0) {
        iota(parent.begin(), parent.end(), 0);
    }

    int find(int x) {
        return parent[x] == x ? x : parent[x] = find(parent[x]);
    }

    bool unite(int u, int v) {
        u = find(u);
        v = find(v);

        if (u == v) return false;

        if (rank[u] < rank[v]) swap(u, v);

        parent[v] = u;

        if (rank[u] == rank[v])
            rank[u]++;

        return true;
    }
};

class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {

        if (connections.size() < n - 1)
            return -1;

        DSU dsu(n);

        for (auto &e : connections)
            dsu.unite(e[0], e[1]);

        int components = 0;

        for (int i = 0; i < n; i++)
            components += (dsu.find(i) == i);

        return components - 1;
    }
};