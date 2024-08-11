class Solution {
public:
    int mod = 1e9+7;
    int solve(int i,int a,int b,vector<int> & nums, vector<vector<vector<int>>> &dp){
        if(i==nums.size()){
            return 1;
        }
        if(dp[i][a][b]!=-1) return dp[i][a][b];
        int sum = 0;
        for(int j=0;j<=nums[i];j++){
            int k = nums[i]-j;
            if(j>=a && k<=b) sum= (sum + solve(i+1,j,k,nums,dp)%mod)%mod;
        }
        return dp[i][a][b] = sum%mod;
    }
    int countOfPairs(vector<int>& nums) {
        int n = nums.size();
        vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(52,vector<int>(52,-1)));
        return solve(0,0,51,nums,dp);
    }
};