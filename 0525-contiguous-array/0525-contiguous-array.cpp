class Solution {
public:
    int findMaxLength(vector<int>& nums){
        map<int,int> mp;
        int sum = 0;
        int ans = 0;
        mp[sum]=-1;
        for(int i = 0; i < nums.size() ;i++){
            if(nums[i]==0) sum--;
            else sum++;

            if(mp.find(sum)!=mp.end()){
                ans = max(ans,i-mp[sum]);
            }
            else{
                mp[sum] = i ;
            }
        }
        return ans;
    }
};