class Solution {
public:
    int m, n;
    vector<vector<int>> memo;
    string s, p;

    bool solve(int i, int j) {
        // Base case
        if (j == n) return i == m;

        // Cache check
        if (memo[i][j] != -1) return memo[i][j];

        // Computation
        bool firstMatch = (i < m) && (p[j] == s[i] || p[j] == '.');

        bool ans;
        if (j + 1 < n && p[j + 1] == '*') {
            ans = solve(i, j + 2) || (firstMatch && solve(i + 1, j));
        } else {
            ans = firstMatch && solve(i + 1, j + 1);
        }

        return memo[i][j] = ans;
    }

    bool isMatch(string s, string p) {
        this->s = s;
        this->p = p;
        m = s.size();
        n = p.size();
        memo.assign(m + 1, vector<int>(n + 1, -1));
        return solve(0, 0);
    }
};