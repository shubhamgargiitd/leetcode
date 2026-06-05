class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (n <= 1) return 0;

        int held = -prices[0];
        int sold = 0;
        int cooldown = 0;

        for (int i = 1; i < n; ++i) {
            int prev_held = held;
            int prev_sold = sold;
            int prev_cooldown = cooldown;

            held = max(prev_held, prev_cooldown - prices[i]);
            sold = prev_held + prices[i];
            cooldown = max(prev_cooldown, prev_sold);
        }

        return max(sold, cooldown);
    }
};