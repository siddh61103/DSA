class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        int n = nums.size();
        int sum = 0 ;
        for(int i=0;i < (1<<n);i++){
            int a = 0;
            for(int j=0;j<n;j++){
                if((i & (1<<j))!=0){
                    a^=nums[j];
                }
            }
            sum+=a;
        }
        return sum;
    }
};