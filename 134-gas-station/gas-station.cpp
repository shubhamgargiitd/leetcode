class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        vector<int> diff; 
        int n = gas.size();
        for(int i = 0; i < n; ++i){
            diff.push_back(gas[i]-cost[i]);
        }

        int ans = -1; 

        for(int i = 0; i < 2*n; ++i){
            if(diff[i%n] >= 0){
                int sum = diff[i%n];
                int idx = i;
                
                while(sum >= 0){
                    i++;
                    sum += diff[i%n];
                    if((i - idx) == n && sum >=0){
                        return i%n; 
                        
                    }
                }

            }
        }
        return ans;
    }
};