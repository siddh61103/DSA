class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        if(k==n) return;
        
        if(k>n) k = k % n;
        int m = n-k;
        reverse(nums.begin(),nums.begin() + m);
        reverse(nums.begin() + m,nums.end());
        reverse(nums.begin(), nums.end());
        return;
    }
};