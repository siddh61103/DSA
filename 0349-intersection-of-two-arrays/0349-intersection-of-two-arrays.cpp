class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        set<int> s;
        vector<int> ans;
        for(auto i:nums1){
            s.insert(i);
        }
        for(auto i:nums2){
            if(s.find(i)!=s.end()){
                s.erase(i);
                ans.push_back(i);
            }
        }
        return ans;
    }
};