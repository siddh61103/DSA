class Solution {
public:
    int solve(vector<vector<int>>& grid, int r, int c, vector<vector<int>>& dp){
        if(dp[r][c]!=-1e9) return max(0,dp[r][c]);
        int a = 0;
        int i = -1e9;
        int j = -1e9;
        int node = grid[r][c];
        if(r+1 < grid.size()){
            a = grid[r+1][c] - grid[r][c];
            i = a + solve(grid, r+1, c, dp);
        }
        if(c+1 < grid[0].size()){
            a = grid[r][c+1] - grid[r][c];
            j = a + solve(grid, r, c+1, dp);
        }
        dp[r][c] = max(i,j);
        return max(0,dp[r][c]);
    }
    int maxScore(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>>dp(n,vector<int>(m,-1e9));
        int ans = -1e9;
        solve(grid,0,0,dp);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                ans = max(ans,dp[i][j]);
            }
        }
        return ans;
    }
};