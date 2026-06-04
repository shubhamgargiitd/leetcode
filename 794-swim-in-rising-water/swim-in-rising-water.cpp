class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        
        int dirs[5] = {-1, 0, 1, 0, -1};
        
        // Custom tuple tracking: {max_elevation_so_far, r, c}
        pq.push({grid[0][0], 0, 0});
        visited[0][0] = true;
        
        while (!pq.empty()) {
            auto curr = pq.top();
            pq.pop();
            
            int t = curr[0], r = curr[1], c = curr[2];
            
            if (r == n - 1 && c == n - 1) return t;
            
            for (int i = 0; i < 4; ++i) {
                int nr = r + dirs[i], nc = c + dirs[i + 1];
                if (nr >= 0 && nr < n && nc >= 0 && nc < n && !visited[nr][nc]) {
                    visited[nr][nc] = true;
                    pq.push({max(t, grid[nr][nc]), nr, nc});
                }
            }
        }
        
        return 0;
    }
};