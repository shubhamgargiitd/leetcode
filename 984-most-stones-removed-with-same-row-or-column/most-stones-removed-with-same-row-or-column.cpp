class Solution {
private:
    void dfs(int src, const vector<vector<int>>& stones, vector<bool>& visited,
             const unordered_map<int, vector<int>>& rowMap, 
             const unordered_map<int, vector<int>>& colMap) {
        
        visited[src] = true;
        int r = stones[src][0];
        int c = stones[src][1];
        
        // Traverse all stones in the same row
        for (int neighbor : rowMap.at(r)) {
            if (!visited[neighbor]) {
                dfs(neighbor, stones, visited, rowMap, colMap);
            }
        }
        
        // Traverse all stones in the same column
        for (int neighbor : colMap.at(c)) {
            if (!visited[neighbor]) {
                dfs(neighbor, stones, visited, rowMap, colMap);
            }
        }
    }

public:
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        unordered_map<int, vector<int>> rowMap, colMap;
        
        // Group stone indices by their row and column coordinates
        for (int i = 0; i < n; ++i) {
            rowMap[stones[i][0]].push_back(i);
            colMap[stones[i][1]].push_back(i);
        }
        
        vector<bool> visited(n, false);
        int numComponents = 0;
        
        for (int i = 0; i < n; ++i) {
            if (!visited[i]) {
                dfs(i, stones, visited, rowMap, colMap);
                numComponents++; // Found a new connected component
            }
        }
        
        return n - numComponents;
    }
};