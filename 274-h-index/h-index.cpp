class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        sort(citations.rbegin(), citations.rend());
        int ans = 0; 
        for(int i = 0; i < n; ++i){
            if(citations[i]>=i+1) ans = i+1;
        }
        return ans; 
    }
};