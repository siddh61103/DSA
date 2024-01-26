class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList)
    {
        unordered_set<string> set(wordList.begin(),wordList.end());
        queue<pair<string,int>>q;
        if(set.find(endWord) == set.end()) return 0;
        q.push({beginWord,1});
        while(!q.empty()){
            string k = q.front().first;
            int n = q.front().second;
            if(k == endWord) return n;
            q.pop();
            for(int i = 0; i < k.size(); i++){
                char original = k[i];
                for(char ch = 'a';ch<='z';ch++){
                    k[i]=ch;
                    if(set.find(k)!= set.end()){
                        q.push({k,n+1});
                        set.erase(k);
                    }
                }
                k[i] = original;
            }
        }
        return 0;
    }
};