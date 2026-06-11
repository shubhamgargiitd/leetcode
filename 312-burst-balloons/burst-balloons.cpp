class Solution {
public:
    int solve(int i, int j, vector<int>& a, vector<vector<int>>& memo) {
        if (j - i < 2) return 0;                  // no balloon strictly inside
        if (memo[i][j] != -1) return memo[i][j];

        int res = 0;
        for (int k = i + 1; k < j; k++) {
            res = max(res, solve(i, k, a, memo) + solve(k, j, a, memo)
                         + a[i] * a[k] * a[j]);
        }
        return memo[i][j] = res;
    }

    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        vector<int> a(n + 2, 1);
        for (int i = 0; i < n; i++) a[i + 1] = nums[i];
        vector<vector<int>> memo(n + 2, vector<int>(n + 2, -1));
        return solve(0, n + 1, a, memo);
    }
};