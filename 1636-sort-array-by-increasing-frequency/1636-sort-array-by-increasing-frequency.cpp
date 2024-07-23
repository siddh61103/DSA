class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        map<int,int> mp;
        vector<int> ans;
        for(auto i : nums) mp[i]++;
        vector<vector<int>> vec(nums.size()+1);
        for(auto i : mp){
            vec[i.second].push_back(i.first);
        }
        for(int i=0;i<vec.size();i++){
            for(int k=vec[i].size()-1;k>=0;k--){
                for(int j=0;j<i;j++){
                    ans.push_back(vec[i][k]);
                }                  
            }
        }
        return ans;
    }
};