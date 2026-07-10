class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        vector<vector<int>> ans(m, vector<int>(n, -1));
        queue<pair<int, int>> q; 
        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                if(mat[i][j] == 0){
                    q.push({i, j});
                    //have to declare queue
                    ans[i][j] = 0;
                }
                }
            }
        vector<pair<int, int>> dir = {{1,0},{0,1}, {-1,0}, {0,-1}};
        while(!q.empty()){ 
            auto[i, j] = q.front(); q.pop();
            for(auto[x,y] : dir){
                int nr = i + x; int nc = j + y; 
                if(nr >= 0 && nr < m && nc >= 0 && nc < n ){
                    if(ans[nr][nc] == -1){
                        ans[nr][nc] = ans[i][j] + 1; 
                        q.push({nr, nc});
                    }
                    
                }
            }
        }
        return ans; 
    }        
};