class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        vector<int> vec;
        vector<string> ans;
        map<int,string> mp;
        
        vec = score;
        sort(vec.begin(),vec.end());
        reverse(vec.begin(),vec.end());
        for(int i=0;i<vec.size();i++){
            if(i==0) mp[vec[i]] = "Gold Medal";
            else if(i==1) mp[vec[i]] = "Silver Medal";
            else if(i==2) mp[vec[i]] = "Bronze Medal";
            else mp[vec[i]] = to_string(i+1);
        }
        for(auto i : score){
            ans.push_back(mp[i]);
        }
        return ans;
    }
};