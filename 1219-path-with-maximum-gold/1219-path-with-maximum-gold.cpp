class Solution {
public:
    int solve(int row, int col, vector<vector<int>>& grid, vector<vector<int>> &dp){
        int n = grid.size();
        int m = grid[0].size();
        int drow[] = {1,0,-1,0};
        int dcol[] = {0,1,0,-1};
        int a = 0;
        for(int i=0; i<4; i++){
            int r = row + drow[i];
            int c = col + dcol[i];
            if(r>=0 && c>=0 && r<n && c<m && dp[r][c]==-1 && grid[r][c]!=0){
                dp[r][c] = 0;
                int m  = solve(r, c, grid, dp);
                dp[r][c] = -1;
                a = max(a,m);
            }
        }
        return dp[row][col] = a + grid[row][col];
    }
    int getMaximumGold(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int ans = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==0) continue;
                vector<vector<int>> dp(n,vector<int>(m,-1));
                dp[i][j] = 0;
                int k = solve(i, j, grid, dp);
                ans = max(ans,k);
            }
        }
        return ans;
    }
};