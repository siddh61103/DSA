class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int sum  = 1;
        int totalsum = 1;
        vector<int> ans(nums.size(),0);
        int zero = 0;
        for(int i : nums){
            if(i!=0){
                sum = sum *i;
            }
            if(i==0) zero++;
            totalsum = totalsum * i;
        }
        if(zero>1) return ans;
        for(int i=0;i<ans.size();i++){
            if(nums[i]==0){
                ans[i] = sum;
            }
            else{
                ans[i] = totalsum / nums[i];
            }
        }
        return ans;
    }
};