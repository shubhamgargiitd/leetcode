class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> res;
        int n = s.size(), num_words = words.size(), k = words[0].size();
        if (n < num_words * k) return res;

        unordered_map<string, int> freq;
        for (const string& w : words) freq[w]++;

        for (int offset = 0; offset < k; ++offset) {
            unordered_map<string, int> seen;
            int count = 0, left = offset;

            for (int right = offset; right + k <= n; right += k) {
                string word = s.substr(right, k);

                if (freq.count(word)) {
                    seen[word]++;
                    count++;

                    // Shrink window if word count exceeds target frequency
                    while (seen[word] > freq[word]) {
                        seen[s.substr(left, k)]--;
                        count--;
                        left += k;
                    }

                    if (count == num_words) res.push_back(left);
                } else {
                    seen.clear();
                    count = 0;
                    left = right + k;
                }
            }
        }

        return res;
    }
};