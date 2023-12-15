class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        string ans;
        map<string,string> mp;
        for(int i = 0; i < paths.size(); i++){
            mp[paths[i][0]] = paths[i][1];
        }
        string m = paths[0][0]; 
        while(mp.find(m)!=mp.end()){
            m = mp[m];
            ans = m;
        }
        return ans;
    }
};