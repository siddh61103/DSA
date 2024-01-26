class Solution {
    unordered_map<string,int> map;
    vector<vector<string>> ans;
    string b;
private:
    void dfs(string word,vector<string> &vec){
        int m = map[word];
        if(word == b){
            reverse(vec.begin(),vec.end());
            ans.push_back(vec);
            reverse(vec.begin(),vec.end());
            return ;
        }
        for(int i = 0; i < word.size(); i++){
            char original = word[i];
            for(char ch = 'a';ch<='z';ch++){
                word[i]=ch;
                 if(map.find(word)!= map.end() && map[word]+1==m){
                    vec.push_back(word);
                    dfs(word,vec);
                    vec.pop_back();
                }
            }
            word[i] = original;
        }
    }

public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> set(wordList.begin(),wordList.end());
        queue<string> q;
        q.push(beginWord);
        b = beginWord;
        map[beginWord] = 1;
        set.erase(beginWord);
        while(!q.empty()){
            string k = q.front();
            int steps = map[k];
            q.pop();
            for(int i = 0; i < k.size(); i++){
                char original = k[i];
                for(char ch = 'a';ch<='z';ch++){
                    k[i]=ch;
                    if(set.find(k)!= set.end()){
                        q.push(k);
                        map[k] = steps+1;
                        set.erase(k);
                    }
                }
                k[i] = original;
            }
        }
        if(map.find(endWord) != map.end()){
            vector<string> vec;
            vec.push_back(endWord);
            dfs(endWord,vec);
        }
        return ans;
    }
};