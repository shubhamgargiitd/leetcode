class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.length(), n = p.length();
        
        // dp[i][j] stores whether s[0...i-1] matches p[0...j-1]
        vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));
        
        // Base case: empty string matches empty pattern
        dp[0][0] = true; 
        
        // Initialize the first row (empty string 's' vs pattern 'p')
        // dp[0][j] can only be true if the pattern character is '*' and the previous state was true
        for (int j = 1; j <= n; ++j) {
            if (p[j - 1] == '*') {
                dp[0][j] = dp[0][j - 1];
            }
        }
        
        // Fill the 2D grid
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (p[j - 1] == '*') {
                    // Two choices for '*':
                    // 1. Act as empty sequence -> check dp[i][j-1] (left)
                    // 2. Match current character -> check dp[i-1][j] (up)
                    dp[i][j] = dp[i][j - 1] || dp[i - 1][j];
                } else if (p[j - 1] == '?' || s[i - 1] == p[j - 1]) {
                    // Characters match or '?' matches any character -> check dp[i-1][j-1] (diagonal up-left)
                    dp[i][j] = dp[i - 1][j - 1];
                } else {
                    // Characters mismatch
                    dp[i][j] = false;
                }
            }
        }
        
        // The bottom-right cell contains the answer for the full strings
        return dp[m][n];
    }
};