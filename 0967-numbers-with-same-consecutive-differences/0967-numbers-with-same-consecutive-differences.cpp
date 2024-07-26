class Solution {
public:
    void solve(int i, int n, vector<int> &ans, int k, int a){
        if(n==0){
            ans.push_back(a);
            return ;
        }
        int h = i-k;
        int m = i+k;
        if(h>=0 && h<=9) solve(h,n-1,ans,k,a*10+h);
        if(h!=m && m>=0 && m<=9) solve(m,n-1,ans,k,a*10+m);
        return ;
    }
    vector<int> numsSameConsecDiff(int n, int k) {
        map<int,vector<int>> mp;
        vector<int> ans;
        n-=1;
        for(int i=1;i<=9;i++){
            solve(i,n,ans,k,i);
        }
        return ans;
    }
};