class Solution {
public:
int mod = 1e9+7;
    int solve(int n, int a, int l,vector<vector<vector<int>>> &dp){
        if(n==0) return 1;
        long long  sum = 0;
        if(a==0){
            if(dp[n-1][a+1][0]!=-1){
                sum+=dp[n-1][a+1][0];
            }
            else sum+=solve(n-1,a+1,0, dp);
        }
        if(l<2){
            if(dp[n-1][a][l+1]!=-1){
                sum+=dp[n-1][a][l+1];
            }
            sum+=solve(n-1,a,l+1, dp);
        }
        if(dp[n-1][a][0]!=-1){
            sum+=dp[n-1][a][0];
        }
        else sum+=solve(n-1,a,0, dp);

        return dp[n][a][l]=sum % mod;
    }
    int checkRecord(int n) {
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2,vector<int>(3,-1)));
        return solve(n,0,0, dp);
    }
};