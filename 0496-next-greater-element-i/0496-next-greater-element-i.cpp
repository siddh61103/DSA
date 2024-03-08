class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        vector<int>next_great(m,-1);
        vector<int>ans(n,-1);
        stack<int> s;
        next_great[m-1] = -1;
        s.push(nums2[m-1]);
        for(int i=m-2;i>=0;i--){
            while(!s.empty() && s.top()<=nums2[i]){
                s.pop();
            }
            next_great[i] = s.empty() ? -1 : s.top();
            s.push(nums2[i]);
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(nums1[i]==nums2[j]){
                    ans[i]=next_great[j];
                    break;
                }
            }
        }
        return ans;
    }
};