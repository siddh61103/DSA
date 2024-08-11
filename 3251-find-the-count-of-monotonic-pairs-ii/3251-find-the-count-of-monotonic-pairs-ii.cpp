class Solution {
public:
    int countOfPairs(vector<int>& nums) {
        int n = nums.size();
        int mod = 1e9+7;
        vector<vector<int>> dp(n,vector<int>(1001,0));
        for(int i=0;i<=nums[0];i++) dp[0][i] = 1;
        for(int i=1; i<n; i++){
            int ways = 0;
            int prev = 0;
            // j means curr_element
            for(int j=0; j<=nums[i]; j++){
                // if(prev<=min(j,nums[i-1]-nums[i]+j)){ 
                //     ways = (ways+dp[i-1][prev]%mod)%mod;
                //     prev++;
                // };
                // OR 
                if((j>=prev) && (nums[i]-j<=nums[i-1]-prev)){ 
                    ways = (ways+dp[i-1][prev]%mod)%mod;
                    prev++;
                }
                dp[i][j]=ways%mod;
            }
        }
        int ans = 0;
        for(auto i : dp[n-1]) ans = (ans + i)%mod;
        return ans;
    }
};