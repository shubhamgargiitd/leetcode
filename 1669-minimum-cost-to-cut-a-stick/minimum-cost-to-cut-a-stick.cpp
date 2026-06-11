class Solution {
public:
    int solve(int i, int j, vector<int>& c, vector<vector<int>>& memo) {
        if (j - i == 1) return 0;          // no cut strictly between => free
        if (memo[i][j] != -1) return memo[i][j];

        int res = INT_MAX;
        for (int k = i + 1; k < j; k++) {
            int curr = solve(i, k, c, memo) + solve(k, j, c, memo)
                     + (c[j] - c[i]);
            res = min(res, curr);
        }
        return memo[i][j] = res;
    }

    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin(), cuts.end());

        int m = cuts.size();
        vector<vector<int>> memo(m, vector<int>(m, -1));
        return solve(0, m - 1, cuts, memo);
    }
};