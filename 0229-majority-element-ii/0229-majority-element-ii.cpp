class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int a = 1e9+1;
        int cnt1 = 0;
        int b = 1e9+1;
        int cnt2 = 0;
        int n= nums.size();
        for(auto i : nums){
            bool k = true;
            if(cnt1==0 && b!=i){
                a=i;
                cnt1++;
            }
            else if(cnt2==0 && a!=i){
                b=i;
                cnt2++;
            }
            else if(a==i){
                cnt1++;
            }
            else if(b==i){
                cnt2++;
            }
            else{
                cnt1--;
                cnt2--;
            }
        }
        cnt1=0;
        cnt2=0;
        for(auto i: nums){
            if(a==i) cnt1++;
            if(b==i) cnt2++;
        }
        if(cnt1>n/3 && a==b) return {a};
        vector<int> vec;
        if(cnt1>n/3) vec.push_back(a);
        if(cnt2>n/3) vec.push_back(b);
        return vec;
    }
};