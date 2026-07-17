class Solution {
public:
    int solve(int i, int start, vector<int>& nums, vector<int>& dp) {
        if (i < start) return 0;
        if (dp[i] != -1) return dp[i];
        return dp[i] = max(solve(i - 1, start, nums, dp),
                            nums[i] + solve(i - 2, start, nums, dp));
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];

        vector<int> dp1(n, -1), dp2(n, -1);
        int case1 = solve(n - 1, 1, nums, dp1); // skip first house
        int case2 = solve(n - 2, 0, nums, dp2); // skip last house

        return max(case1, case2);
    }
};