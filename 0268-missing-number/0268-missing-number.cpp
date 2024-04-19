class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int a = nums.size()*(nums.size()+1)/2;
        for(auto i : nums){
            a-=i;
        }
        return a;
    }
};