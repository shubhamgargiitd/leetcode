class Solution {
public:
    void dfs(int node,vector<vector<int>>& isConnected, vector<int> &visited, int& n){
        visited[node ] = 1;

        for(int i = 0; i < n; ++i){
            if(isConnected[node][i] && !visited[i]){
                dfs(i, isConnected, visited, n);
            }
        }


    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();

        vector<int> visited(n, 0);
        int provinces = 0; 

        for(int i = 0 ; i < n; ++i){
            if(visited[i] == 0){
                dfs(i, isConnected, visited, n);
                provinces ++;
            }
        }    

        return provinces;
    }
};