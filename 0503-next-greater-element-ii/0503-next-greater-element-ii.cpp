class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        stack<int> s;
        for(int i=n-2;i>=0;i--){
            if(nums[i]>nums[n-1]){
                s.push(nums[i]);
            }
        }
        vector<int> ans(n,-1);
        ans[n-1] = s.empty() ? -1:s.top();
        s.push(nums[n-1]);
        for(int i=n-2;i>=0;i--){
            while(!s.empty() && s.top()<=nums[i]){
                s.pop();
            }
            ans[i] = s.empty()? -1:s.top();
            s.push(nums[i]); 
        }
        return ans;
    }
};