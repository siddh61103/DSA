class Solution {
public:
    void solve(int i, vector<int> &vec,vector<int> &nums, vector<vector<int>> &ans){
        if(i==nums.size()){
            ans.push_back(vec);
            return ;
        }
        vec.push_back(nums[i]);
        solve(i+1,vec,nums, ans);
        vec.pop_back();
        solve(i+1,vec,nums, ans);
        return ;
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> vec;
        solve(0,vec,nums,ans);
        return ans;
    }
};