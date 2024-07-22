class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        map<int,int> mp;
        for(int i=0;i<heights.size();i++){
            mp[heights[i]] = i;
        }
        vector<string> vec;
        for(auto i :mp) vec.push_back(names[i.second]);
        reverse(vec.begin(),vec.end());
        return vec;
    }
};