class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.empty()) return 0;
        
        // Base States
        int holding = -prices[0]; // Cash after buying on day 0
        int not_holding = 0;      // Cash if we do nothing
        
        for (int i = 1; i < prices.size(); ++i) {
            // Can choose to keep holding or buy for the first time today
            holding = max(holding, -prices[i]);
            
            // Can choose to stay liquid or sell the held stock today
            not_holding = max(not_holding, holding + prices[i]);
        }
        
        return not_holding;
    }
};