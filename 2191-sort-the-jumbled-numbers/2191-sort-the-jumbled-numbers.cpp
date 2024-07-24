class Solution {
public:
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        multimap<int,int> mp;
        for(auto i : nums){
            int n = i;
            int a = 0;
            int m = 1;
            while(n!=0){
                a = a+(mapping[n%10])*m;
                m*=10;
                n = n/10;
            }
            if(i==0) mp.insert(pair<int,int>(mapping[i],i));
            else mp.insert(pair<int,int>(a,i));
        }
        vector<int> ans;
        for(auto i: mp){
            ans.push_back(i.second);
        }
        return ans;
    }
};