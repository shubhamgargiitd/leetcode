class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        
        vector<pair<int,int>> adj[n+1];
        for(auto &t : times) {
            adj[t[0]].push_back({t[1], t[2]});
        }
        vector<int> dist(n+1, INT_MAX);
        dist[k] = 0;
        dist[0] = -1;

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        pq.push({0, k});
        
        while(!pq.empty()) {
            auto [time, node] = pq.top();
            pq.pop();
            
            for(auto &it : adj[node]) {
                int adjNode = it.first;
                int edgeWeight = it.second;
                
                if(time + edgeWeight < dist[adjNode]) {
                    dist[adjNode] = time + edgeWeight;
                    pq.push({dist[adjNode], adjNode});
                }
            }
        }
        int maxi = *max_element(dist.begin(), dist.end());
        if(maxi == INT_MAX) return -1;
        return maxi;
    }
};