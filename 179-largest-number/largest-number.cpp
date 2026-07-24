class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> arr;

        // convert to string
        for (int x : nums) { 
            arr.push_back(to_string(x));
        }

        // custom sort
        sort(arr.begin(), arr.end(), [](string &a, string &b){
            return a + b > b + a; 
        });

        // edge case: all zeros
        if (arr[0] == "0") return "0";

        // build answer
        string result = "";
        for (string s : arr) {
            result += s;
        }

        return result;
    }
};

