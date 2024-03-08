class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        vector<int>next_great(m,-1);
        vector<int>ans(n,-1);
        priority_queue<int,vector<int>,greater<int>> pq;
        next_great[m-1] = -1;
        pq.push(nums2[m-1]);
        for(int i=m-2;i>=0;i--){
            while(pq.top()<=nums2[i] && pq.size()!=0){
                pq.pop();
            }
            if(pq.size()==0){
                pq.push(nums2[i]);
            }
            else{
                next_great[i]=pq.top();
                pq.push(nums2[i]);
            }
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