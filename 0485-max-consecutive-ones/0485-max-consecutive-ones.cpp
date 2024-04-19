class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int ans = 0;
        int s = 0;
        for(auto i : nums){
            s+=i;
            if(i==0)s=0;
            ans = max(ans,s);
        }
        return ans;
    }
};