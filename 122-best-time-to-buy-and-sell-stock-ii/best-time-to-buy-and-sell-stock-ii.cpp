class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.empty()) return 0;

        int holding = -prices[0]; // Profit after buying on day 0
        int not_holding = 0;      // Profit if we do nothing on day 0

        for (int i = 1; i < prices.size(); ++i) {
            int prev_not_holding = not_holding;

            // Decision: Keep holding, or buy today using past profits
            holding = max(holding, prev_not_holding - prices[i]);

            // Decision: Stay cash-heavy, or sell today's stock for cash
            not_holding = max(not_holding, holding + prices[i]);
        }

        return not_holding;
    }
};