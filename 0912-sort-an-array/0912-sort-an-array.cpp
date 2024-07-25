class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        int n=nums.size();
        map<int,int> mp;
        for(auto i: nums){
            mp[i]++;
        }
        int sum = 0;
        for(auto i : mp){
            mp[i.first] = sum+=i.second;
            sum = mp[i.first];
        }
        vector<int> ans(n);
        for(int i=0;i<n;i++){
            ans[mp[nums[i]]-1] = nums[i];
            mp[nums[i]]--;
        }
        return ans;
    }
};