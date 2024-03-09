class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        set<int> s;
        for(auto i : nums1){
            s.insert(i);
        }
        int ans = 1e9+1;
        for(auto i : nums2){
            if(s.find(i)!=s.end()){
                ans = min(ans,i);
            }
        }
        if(ans==1e9+1) return -1;
        return ans;
    }
};