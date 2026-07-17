class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        
        vector<pair<int,int>> adj[n];
        for(auto &f : flights) {
            adj[f[0]].push_back({f[1], f[2]});
        }

        vector<int> dist(n, INT_MAX);
        dist[src] = 0;
        
        queue<tuple<int,int,int>> q;
        q.push({0, src, 0});
        
        while(!q.empty()) {
            auto [stops, node, cost] = q.front();
            q.pop();
            
            if(stops > k) continue;
            
            for(auto &it : adj[node]) {
                int adjNode = it.first;
                int edgeCost = it.second;
                
                if(cost + edgeCost < dist[adjNode]) {
                    dist[adjNode] = cost + edgeCost;
                    q.push({stops + 1, adjNode, dist[adjNode]});
                }
            }
        }
        
        return (dist[dst] == INT_MAX) ? -1 : dist[dst];
    }
};