class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int temp = 0;
        for(int i=0;i<n;i++ ){
            if(temp<i){
                return false;
            }
            temp = max( temp, i + nums[i]);
        }
        return true;
    }
};

// [2,3,1,1,4]
// [3,0,8,2,0,0,1]
// [3,2,1,0,4]