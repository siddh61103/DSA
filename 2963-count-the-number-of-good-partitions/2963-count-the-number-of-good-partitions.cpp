class Solution {
public:
    int numberOfGoodPartitions(vector<int>& nums) {
        map<int,int>mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]] = i;
        }
        
        int maxi= -1;
        long long int ans = 1;
        int count = 0;
        for(int i = 0;i<nums.size();i++){
            maxi = max(maxi,mp[nums[i]]);
            if(maxi==i){
                maxi =-1;
                count++;
                if(count>1){
                    ans = (ans *2) % 1000000007;
                }
            }
        }
        return ans;
    }
};