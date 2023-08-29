class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int count=0;
        
        while(true){

            int f = 0;
            for(int i=0; i<nums.size(); i++){
                if(nums[i] == val){
                    nums.erase(nums.begin() + i);
                    f = 1;
                    break;
                }
            }
            if(f == 0) break;
        }
        return nums.size();
    }
};