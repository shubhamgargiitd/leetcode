class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();

        vector<int> color(n, -1);

        for(int i = 0; i < n ; ++i){
            if(color[i] != -1) continue; 

            queue<int> q; 
            q.push(i);
            color[i] = 0;

            while(!q.empty()){
                int curr = q.front(); q.pop();

                for(int nei : graph[curr]){
                    if(color[nei] == -1){
                        q.push(nei);
                        color[nei] = 1 -color[curr];
                    }else if(color[nei] == color[curr]){
                        return false;
                    }
                }


            }


        }

        return true;




    }
};