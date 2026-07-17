using P = pair<long long,int>;
using Edge = pair<int,int>;

class Solution {
public:
    const long long MOD = 1e9+7;
    int countPaths(int n, vector<vector<int>>& roads) {

        vector<vector<Edge>> adj(n);

        for (auto &r : roads) {
            adj[r[0]].emplace_back(r[1], r[2]);
            adj[r[1]].emplace_back(r[0], r[2]);
        }

        vector<long long> dist(n, LLONG_MAX), ways(n);

        priority_queue<P, vector<P>, greater<P>> pq;

        dist[0] = 0;
        ways[0] = 1;
        pq.emplace(0, 0);

        while (!pq.empty()) {
            auto [d, u] = pq.top();
            pq.pop();

            if (d > dist[u]) continue;

            for (auto &[v, wt] : adj[u]) {
                auto newDist = d + wt;

                if (newDist < dist[v]) {
                    dist[v] = newDist;
                    ways[v] = ways[u];
                    pq.emplace(newDist, v);
                }
                else if (newDist == dist[v]) {
                    ways[v] = (ways[v] + ways[u]) % MOD;
                }
            }
        }

        return ways[n - 1];
    }
};