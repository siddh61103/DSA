class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        set<vector<int>> set;
        for(int i=0;i<nums.size();i++){
            int s = i+1;
            int e = nums.size()-1;
            while(s<e){
                int a = nums[i]+nums[s]+nums[e];
                if(a==0){
                    set.insert({nums[i],nums[s],nums[e]});
                    s++;
                    e--;
                }
                else if(a>0){
                    e--;
                }
                else{
                    s++;
                }
            }
        }
        for(auto i : set){
            ans.push_back(i);
        }
        return ans;
    }
};