#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        priority_queue<int> live_heap;
        priority_queue<int> delete_heap;
        vector<int> result;

        // 1. Fill the first window
        for (int i = 0; i < k; ++i) {
            live_heap.push(nums[i]);
        }
        result.push_back(live_heap.top());

        // 2. Slide the window across the rest of the array
        for (int i = k; i < nums.size(); ++i) {
            // Push the new incoming element
            live_heap.push(nums[i]);
            
            // The leftmost element exits the window; track it for deletion
            delete_heap.push(nums[i - k]);

            // Lazy deletion loop: if the current maximums match, cancel them out
            while (!delete_heap.empty() && !live_heap.empty() && live_heap.top() == delete_heap.top()) {
                live_heap.pop();
                delete_heap.pop();
            }

            // The top of the live heap is our maximum for the current window
            result.push_back(live_heap.top());
        }

        return result;
    }
};