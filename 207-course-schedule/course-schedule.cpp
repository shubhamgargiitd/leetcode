class Solution {
public:


    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adjlist(numCourses); 
        vector<int> state (numCourses, 0);
        vector<int> indegree(numCourses);
        for(auto e : prerequisites){
            adjlist[e[0]].push_back(e[1]);
            indegree[e[1]]++;



        }

        queue<int> q; 
        int coursesdone = 0; 
        for(int i = 0; i < numCourses ; ++i){
            if(indegree[i] == 0){
                q.push(i);
                coursesdone++;

            }
        }


        while(!q.empty()){
            int j = q.front(); q.pop();

            for(int nei : adjlist[j]){
                indegree[nei]--;
                if(indegree[nei] == 0){
                    q.push(nei);
                    coursesdone++;
                }
            }

        
        
        
        }
        return numCourses == coursesdone;
    }
};