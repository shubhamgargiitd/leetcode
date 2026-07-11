class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        int n = wordList.size();
        queue<string> q;
        set<string> st;
        unordered_map<string, vector<string>> parents;

        for(int i = 0; i < n; ++i){
            st.insert(wordList[i]);
        }

        vector<vector<string>> result;
        if(!st.count(endWord)) return result;

        q.push(beginWord);
        st.erase(beginWord);
        bool found = false;

        while(!q.empty() && !found){
            int levelSize = q.size();
            set<string> visitedThisLevel;

            for(int k = 0; k < levelSize; ++k){
                string currword = q.front(); q.pop();

                int sz = currword.size();
                for(int i = 0; i < sz; ++i){
                    int c = currword[i] - 'a';
                    string temp = currword;
                    for(int j = 1; j < 26; ++j){
                        temp[i] = (c+j)%26 + 'a';

                        if(st.count(temp)){
                            if(!visitedThisLevel.count(temp)){   // FIX: enqueue only once per level
                                q.push(temp);
                            }
                            visitedThisLevel.insert(temp);
                            parents[temp].push_back(currword);    // always record predecessor

                            if(temp == endWord){
                                found = true;
                            }
                        }
                    }
                }
            }

            for(const string& w : visitedThisLevel) st.erase(w);
        }

        if(!found) return result;

        vector<string> path{endWord};
        backtrack(endWord, beginWord, parents, path, result);
        return result;
    }

private:
    void backtrack(const string& word, const string& beginWord,
                    unordered_map<string, vector<string>>& parents,
                    vector<string>& path, vector<vector<string>>& result){
        if(word == beginWord){
            vector<string> p(path.rbegin(), path.rend());
            result.push_back(p);
            return;
        }
        if(!parents.count(word)) return;
        for(const string& par : parents[word]){
            path.push_back(par);
            backtrack(par, beginWord, parents, path, result);
            path.pop_back();
        }
    }
};