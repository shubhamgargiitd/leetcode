class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> result;
        vector<vector<int>> adjlist(numCourses); 
        vector<int> state (numCourses, 0);
        vector<int> indegree(numCourses);
        for(auto e : prerequisites){
            adjlist[e[1]].push_back(e[0]);
            indegree[e[0]]++;
        }

        queue<int> q; 
        int coursesdone = 0; 
        for(int i = 0; i < numCourses ; ++i){
            if(indegree[i] == 0){
                q.push(i);
                result.push_back(i);
                coursesdone++;

            }
        }


        while(!q.empty()){
            int j = q.front(); q.pop();

            for(int nei : adjlist[j]){
                indegree[nei]--;
                if(indegree[nei] == 0){
                    q.push(nei);
                    result.push_back(nei);
                    coursesdone++;
                }
            }

        
        
        
        }
        if(numCourses == coursesdone){
            return result;
        } 
        else return {};
    }
    };


