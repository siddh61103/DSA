class Solution {
public:
typedef pair<int, int> pairs; 
    int findPairs(vector<int>& nums, int k) {
        int n = nums.size();
        set<pair<int,int>> s;
        map<int,int> mp;
        for(int i=0;i<n;i++){
            mp[nums[i]]++;
        }
        for(int i=0;i<n;i++){
            int temp = nums[i];
            int m = temp + k;
            if(temp==m){
                if(mp[m]>1){
                    s.insert({temp,m});
                }
            }
            else{
                if(mp[m]>=1){
                    s.insert({temp,m});
                }
            }
        }
        return s.size();
    }
};