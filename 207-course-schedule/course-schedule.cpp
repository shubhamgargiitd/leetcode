class Solution {
public:
    bool dfs(int node, vector<vector<int>> &adjlist, vector<int> &state){

        if(state[node ] == 1) return true; 
        if(state[node ] == 2) return false; 

        state[node ] = 1; 

        for(auto nei : adjlist[node]){
            if(dfs(nei, adjlist, state)){
                return true; 
            }
        }
        state[node] = 2; 
        return false; 
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adjlist(numCourses); 
        vector<int> state (numCourses, 0);
        for(auto e : prerequisites){
            adjlist[e[1]].push_back(e[0]);
        }

        for(int i = 0; i < numCourses; ++i){
            if(dfs(i, adjlist, state)){
                return false;
            }
        }
        return true; 
    }
};