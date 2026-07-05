class Solution {
public:
    bool makesquare(vector<int>& matchsticks) {
        int totalSum = accumulate(matchsticks.begin(), matchsticks.end(), 0);
        
        // ---- Pruning ----
        if (matchsticks.empty() || totalSum % 4 != 0) return false;
        
        int side = totalSum / 4;
        sort(matchsticks.rbegin(), matchsticks.rend()); // descending order
        
        if (matchsticks[0] > side) return false;
        
        vector<int> sides(4, 0);
        return backtrack(matchsticks, 0, sides, side);
    }
    
private:
    bool backtrack(vector<int>& matchsticks, int index, vector<int>& sides, int side) {
        // ---- Base case ----
        if (index == matchsticks.size()) {
            return true; // all sticks placed, and since sums matched at each step, all 4 sides are equal
        }
        
        // ---- Computation ----
        for (int i = 0; i < 4; ++i) {
            // Skip if adding this stick exceeds the target side length
            if (sides[i] + matchsticks[index] > side) continue;
            
            sides[i] += matchsticks[index];
            if (backtrack(matchsticks, index + 1, sides, side)) {
                return true;
            }
            sides[i] -= matchsticks[index]; // backtrack
        }
        
        return false;
    }
};