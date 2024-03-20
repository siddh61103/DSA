class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int ans = 0;
        int odd = 0;
        int n = nums.size();
        map<int,int> mp;
        mp[0] = 1;
        int j=0;
        while(j<n){
            if(nums[j]%2!=0) odd++;
            ans+=mp[odd-k];
            mp[odd]++;
            j++;
        }
        return ans;
    }
};