class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        vector<int> arr;
        arr.push_back(nums[0]);
        int m =nums[0];
        for(int i=1;i<nums.size();i++){
            if(m!=nums[i] ){
                arr.push_back(nums[i]);
                m = nums[i];
            }
        }
        for(int i=0;i<arr.size();i++){
            nums[i] = arr[i];
        }
        return arr.size();
    }
};