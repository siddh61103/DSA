class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int k = -1;
        for(int i=n-2;i>=0;i--){
            if(nums[i]<nums[i+1]){
                k = i;
                break;
            }
        }
        if(k==-1){
            reverse(nums.begin(),nums.end());
            return ;
        }
        for(int i=n-1;i>k;i--){
            if(nums[i]>nums[k]){
                swap(nums[k],nums[i]);
                break;
            }
        }
        reverse(nums.begin()+k+1,nums.end());
        return ;
    }
};
