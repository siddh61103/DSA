class Solution {
public:
    int solve(int i, int j , string &s, string &m, vector<vector<int>> &dp){
        if(i==0 || j==0) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        if(s[i-1]==m[j-1]) return dp[i][j] = 1 + solve(i-1,j-1,s,m,dp);
        return dp[i][j] = max(solve(i,j-1,s,m,dp), solve(i-1,j,s,m,dp));
    }
    int minInsertions(string s) {
        int n = s.size();
        string m = s;
        reverse(m.begin(),m.end());
        vector<vector<int>> dp(n+1, vector<int>(n+1,-1));
        int k = solve(n,n,s,m,dp);
        return n-k;
    }
};