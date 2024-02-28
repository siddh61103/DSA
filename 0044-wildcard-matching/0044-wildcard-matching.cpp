class Solution {
public:
    bool solve(int i, int j, string &s, string &m, vector<vector<int>>&dp){
        if(j<0 && i<0) return true;
        if(j<0 && i>=0) return false;
        if(i<0 && j>=0){
            for(int k=0; k<=j;k++){
                if(m[k]!='*') return false;
            }
            return true;
        }
        if(dp[i][j]!=-1) return dp[i][j];
        if(s[i]==m[j] || m[j]=='?') return dp[i][j] = solve(i-1, j-1, s, m, dp);
        if(m[j]=='*') {
            bool a = solve(i,j-1,s,m,dp);
            bool b = solve(i-1,j,s,m,dp);
            return dp[i][j] = a | b;
        }
        return dp[i][j] = false;
    }
    bool isMatch(string s, string p) {
        int n = s.size();
        int m = p.size();
        vector<vector<int>>dp(n+1, vector<int>(m+1,-1));
        return solve(n-1,m-1 ,s, p, dp);
    }
};