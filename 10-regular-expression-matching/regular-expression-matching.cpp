class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.size(), n = p.size();
        vector<vector<bool>> dp(n + 1, vector<bool>(m + 1, false));
        dp[0][0] = true;

        // Helper lambda to check if s[i-1] matches p[j-1]
        auto matches = [&](int i, int j) {
            return i > 0 && (p[j - 1] == '.' || p[j - 1] == s[i - 1]);
        };

        for (int j = 1; j <= n; ++j) {
            for (int i = 0; i <= m; ++i) {
                if (p[j - 1] == '*') {
                    dp[j][i] = dp[j - 2][i] || (matches(i, j - 1) && dp[j][i - 1]);
                } else {
                    dp[j][i] = matches(i, j) && dp[j - 1][i - 1];
                }
            }
        }

        return dp[n][m];
    }
};