class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        if (nums.empty()) return {};

        // Step 1: Sort the array to utilize transitivity
        sort(nums.begin(), nums.end());
        
        int n = nums.size();
        vector<int> dp(n, 1);
        vector<int> parent(n, -1);
        
        int max_len = 1;
        int max_index = 0;
        
        // Step 2: Standard DP transition similar to LIS
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                // Check if nums[i] can extend the subset ending at nums[j]
                if (nums[i] % nums[j] == 0 && dp[j] + 1 > dp[i]) {
                    dp[i] = dp[j] + 1;
                    parent[i] = j; // Link i back to its divisor j
                }
            }
            // Track the ending point of the largest subset
            if (dp[i] > max_len) {
                max_len = dp[i];
                max_index = i;
            }
        }
        
        // Step 3: Backtrack using the parent array to reconstruct the subset
        vector<int> result;
        int curr = max_index;
        while (curr != -1) {
            result.push_back(nums[curr]);
            curr = parent[curr];
        }
        
        return result; // Order doesn't matter for the final subset
    }
};