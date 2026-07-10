class Solution {
public:
    bool valid(int i, int j, int n, int m ,int stcl,  vector<vector<int>>& grid){
        if(i >= 0 && i < n && j >= 0 && j < m && grid[i][j] == stcl){
            return true;
        }
        return false; 
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size();
        int m = image[0].size();

        int stcl = image[sr][sc];

        if(stcl == color){
            return image; 

        }

        vector<vector<int>> dir = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

        queue<pair<int, int>> q; 

        q.push({sr, sc});
        image[sr][sc] = color;


        while(!q.empty()){
            auto[i, j ] = q.front(); q.pop();
            for(auto d : dir){
                int nr = d[0] + i; int nc = d[1] + j;
                if(valid(nr, nc, n, m,stcl,  image)){
                    q.push({nr, nc});
                    image[nr][nc] = color;
                }
            }
        }

        return image; 


    }
};