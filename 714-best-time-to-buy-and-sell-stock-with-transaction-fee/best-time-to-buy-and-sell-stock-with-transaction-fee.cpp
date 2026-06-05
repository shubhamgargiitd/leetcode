class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        if (n <= 1) return 0;

        // Base cases for day 0
        int hold = -prices[0]; 
        int free = 0;          

        for (int i = 1; i < n; ++i) {
            int prev_hold = hold;
            
            // Update states for the current day
            hold = max(hold, free - prices[i]);
            free = max(free, prev_hold + prices[i] - fee);
        }

        return free;
    }
};