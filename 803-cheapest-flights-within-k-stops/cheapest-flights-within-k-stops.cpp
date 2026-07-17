class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        
        vector<int> dist(n, INT_MAX);
        dist[src] = 0;
        
        for(int i = 0; i <= k; i++) {
            vector<int> temp = dist;//creating a temp array equal to distance to stop overwriting
            //could have done this without the temp array if there was no condition of k stops
            
            for(auto &flight : flights) {//transversing all the edges 
                int u = flight[0];
                int v = flight[1];
                int cost = flight[2];
                
                if(dist[u] != INT_MAX && dist[u] + cost < temp[v]) {//checking the condition
                    temp[v] = dist[u] + cost;//updating the temp array
                }
            }
            dist = temp;
        }
        return (dist[dst] == INT_MAX) ? -1 : dist[dst];
    }
};