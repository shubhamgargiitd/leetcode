class Solution {
public:
    int solve(vector<int>& nums, int idx, vector<int>& dp) {
        if (idx < 0)
            return 0;

        if (idx == 0)
            return nums[0];

        if (dp[idx] != -1)
            return dp[idx];

        int take = nums[idx] + solve(nums, idx - 2, dp);
        int skip = solve(nums, idx - 1, dp);

        return dp[idx] = max(take, skip);
    }

    int rob(vector<int>& nums) {
        vector<int> dp(nums.size(), -1);
        return solve(nums, nums.size() - 1, dp);
    }
};