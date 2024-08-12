class Solution {
public:
    int solve(int i,string &s,vector<int> &dp){
        if(i==s.size()){ 
            return 1;
        }
        if(dp[i]!=-1) return dp[i];
        int sum = 0;
        string h;
        h=s[i];
        if(s[i]=='0') return 0;
        int n = stoi(h);
        if(n>0 && n<=26) sum+=solve(i+1,s,dp);
        if(i<s.size()-1){
            h+=s[i+1];
            n=stoi(h);
            if(n>0 && n<=26) sum+=solve(i+2,s,dp);
        }
        return dp[i] = sum;
    }
    int numDecodings(string s) {
        vector<int> dp(s.size(),-1);
        return solve(0,s,dp);
    }
};