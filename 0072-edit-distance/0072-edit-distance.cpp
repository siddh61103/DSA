class Solution {
public:
    int solve(int i ,int j,string &s, string &m, vector<vector<int>> &dp){
        if(j<0) return i+1;
        if(i<0) return j+1;
        if(dp[i][j]!=-1) return dp[i][j];
        if(s[i]==m[j]){
            return dp[i][j] = solve(i-1, j-1, s, m, dp);
        }
        int a = solve(i,j-1,s,m, dp); //insert
        int b = solve(i-1,j-1,s,m, dp); //replace
        int c = solve(i-1,j,s,m, dp); //delete
        b = min(b,c);
        return dp[i][j] = 1 + min(a,b); 
    }
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        vector<vector<int>> dp(n, vector<int>(m,-1));
        return solve(n-1, m-1, word1, word2, dp);
    }
};