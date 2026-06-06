class Solution {
public:
    int longestStrChain(vector<string>& words) {
        // Sort words by length so smaller words are processed first
        sort(words.begin(), words.end(), [](const string& a, const string& b) {
            return a.length() < b.length();
        });

        // dp[word] stores the longest chain ending at 'word'
        unordered_map<string, int> dp;
        int max_chain = 1;

        for (const string& word : words) {
            int current_longest = 1;
            
            // Generate all possible predecessors by deleting one character
            for (int i = 0; i < word.length(); ++i) {
                string pred = word.substr(0, i) + word.substr(i + 1);
                
                // If the predecessor exists in our map, try to extend its chain
                if (dp.count(pred)) {
                    current_longest = max(current_longest, dp[pred] + 1);
                }
            }
            
            // Save the result for the current word
            dp[word] = current_longest;
            max_chain = max(max_chain, current_longest);
        }

        return max_chain;
    }
};