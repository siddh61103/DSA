class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        map<int,int> mp;
        int sum =0;
        int ans = 0;
        mp[0]=1;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            ans += mp[sum-goal];
            mp[sum]++;
        }
        return ans;
    }
};