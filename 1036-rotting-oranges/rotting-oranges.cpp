class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        
        int n = grid.size(); int m = grid[0].size();
        int fresh = 0; queue<pair<int, int>> q; 
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < m; ++j){
                if(grid[i][j] == 1) fresh++;
                else if(grid[i][j] == 2 ) q.push({i,j});
            }
        }

        int time = 0; 
        vector<pair<int, int>> dirs = {{0,1}, {0, -1}, {1, 0}, {-1, 0}};
        while(!q.empty() && fresh > 0){
            int s = q.size();
            time++;
           

            for(int k = 0; k < s; ++k){
                auto [i, j] = q.front(); q.pop();

                for(auto [x, y] : dirs){
                    int nr = i +x; int nc = j +y;
                    if(nr <n && nr >=0 && nc < m && nc >= 0 && grid[nr][nc] == 1){
                        q.push({nr, nc});
                        grid[nr][nc] = 2; 
                        fresh--;
                    }
                }
            }
        }

        if(fresh == 0) return time;
        else return -1; 
    }
};