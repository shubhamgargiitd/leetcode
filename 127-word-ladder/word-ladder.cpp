class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int n = wordList.size();
        queue<pair<string, int>>q; 
        set<string> st;
        for(int i = 0; i < n; ++i){
            st.insert(wordList[i]);


        }
        q.push({beginWord, 1});

        while(!q.empty()){
            auto [currword, len] = q.front(); q.pop();
            if(currword == endWord) return len;
            int sz = currword.size();

            for(int i = 0; i < sz; ++i){
                for(int j = 1; j < 26; ++j){
                    string temp = currword; 
                    int c = temp[i] - 'a';
                    temp[i] = (c+j)%26 + 'a';

                    if(st.count(temp)){
                        st.erase(temp);
                        q.push({temp, len+1});
                    }
                }
            }
        }
        return 0;

    }
};