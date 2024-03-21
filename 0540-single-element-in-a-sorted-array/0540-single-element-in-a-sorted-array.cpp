class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return nums[0];
        if(nums[0]!=nums[1]) return nums[0];
        if(nums[n-1]!=nums[n-2]) return nums[n-1];
        int s = 1;
        int e = n-2;
        int mid;
        while(s<=e){
            mid = s + (e-s)/2;
            if(nums[mid-1]!=nums[mid] && nums[mid]!=nums[mid+1] ) return nums[mid];
            
            if((mid%2==0 && nums[mid]==nums[mid-1]) || (mid%2!=0 && nums[mid]==nums[mid+1])){
                e = mid-1;
            }
            else{
                s = mid+1;
            }
        }
        return nums[nums.size()-1];
    }
};