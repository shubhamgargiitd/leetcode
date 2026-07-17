class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int threshold) {

        vector<vector<int>> dist(n, vector<int>(n, 1e9));

        for(int i=0;i<n;i++)
            dist[i][i]=0;

        for(auto &e: edges){
            int u=e[0];
            int v=e[1];
            int w=e[2];

            dist[u][v]=w;
            dist[v][u]=w;
        }

        // Floyd Warshall
        for(int k=0;k<n;k++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    dist[i][j]=min(
                        dist[i][j],
                        dist[i][k]+dist[k][j]
                    );
                }
            }
        }

        int ans=-1;
        int minCount=INT_MAX;

        for(int i=0;i<n;i++){

            int cnt=0;

            for(int j=0;j<n;j++){
                if(dist[i][j] <= threshold)
                    cnt++;
            }

            if(cnt <= minCount){
                minCount=cnt;
                ans=i;
            }
        }

        return ans;
    }
};