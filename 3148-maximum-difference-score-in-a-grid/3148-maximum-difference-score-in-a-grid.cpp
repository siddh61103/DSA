class Solution {
public:
    int maxScore(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>>dp(n,vector<int>(m,-1e9));
        dp[n-1][m-1]=0;
        int ans = -1e9;
        for(int r=n-1; r>=0; r--){
            for(int c=m-1; c>=0; c--){
                int a = 0;
                int i = -1e9;
                int j = -1e9;
                int node = grid[r][c];
                if(r+1 < n){
                    a = grid[r+1][c] - grid[r][c];
                    i = a + dp[r+1][c];
                }
                if(c+1 < m){
                    a = grid[r][c+1] - grid[r][c];
                    j = a + dp[r][c+1];
                }
                ans = max(ans,max(i,j));
                dp[r][c] = max(0,max(i,j));
            }
        }
        return ans;
    }
};