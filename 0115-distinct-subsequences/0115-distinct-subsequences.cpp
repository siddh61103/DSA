class Solution {
public:
    int solve(int i, int j, string &s, string &m,vector<vector<int>> &dp){
        if(dp[i][j]!=-1) return dp[i][j];
        if(j==0) return 1;
        if(i==0) return 0;
        if(s[i-1] == m[j-1]){
            int a = solve(i-1, j-1, s, m, dp);
            int b = solve(i-1,j,s,m,dp);
            return dp[i][j] = a+b;
        }
        return dp[i][j] = solve(i-1, j, s, m, dp);
    }  
    int numDistinct(string s, string t) {
        int n = s.size();
        int m = t.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        return solve(n, m, s, t, dp);
    }
};
