#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        // Max-heap storing pairs of {value, index}
        priority_queue<pair<int, int>> max_heap;
        vector<int> result;

        for (int i = 0; i < nums.size(); ++i) {
            max_heap.push({nums[i], i});

            // Lazy deletion: remove elements from top if they are outside the window
            while (max_heap.top().second <= i - k) {
                max_heap.pop();
            }

            // Start adding to results once the first window is fully formed
            if (i >= k - 1) {
                result.push_back(max_heap.top().first);
            }
        }

        return result;
    }
};