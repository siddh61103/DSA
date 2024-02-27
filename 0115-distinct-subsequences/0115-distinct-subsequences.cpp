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















        // for(int i=1; i<n+1; i++){
        //     for(int j=1; j<m+1; j++){
        //         if(s[i-1]==t[j-1]) dp[i][j] = 1+ dp[i-1][j-1];
        //         else dp[i][j] = max(dp[i][j-1],dp[i-1][j]);
        //     }
        // }
        // int i = n;
        // int j = m;
        // string a = "";
        // int k =0;
        // while(i>0 && j>0){
        //     if(s[i-1]==t[j-1]){
        //         k++;
        //         i--;
        //         j--;
        //     }
        //     else if(dp[i-1][j]>dp[i][j-1]){
        //         a = a + s[i-1];
        //         i--;
        //     }
        //     else{
        //         a = a + t[j-1];
        //         j--;
        //     }
        // }
        // cout<<a;
        // int ans = 0;