class Solution {
public:
    int findMaxK(vector<int>& nums) {
        map<int,int> mp;
        int ans = -1e9;
        for(auto i : nums){
            mp[i]=1;
            ans= max(ans,i);
        }
        for(int i=ans;i>0;i--){
            if(mp[i] && mp[-i]) return i;
        }
        return -1;
    }
};