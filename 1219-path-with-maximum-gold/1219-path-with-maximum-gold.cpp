class Solution {
public:
    vector<int> drow = {1,0,-1,0};
    vector<int> dcol = {0,1,0,-1};
    
    int solve(int row, int col, vector<vector<int>>& grid, int n, int m){
        int a = 0;
        int curr = grid[row][col];
        grid[row][col] = 0;
        for(int i=0; i<4; i++){
            int r = row + drow[i];
            int c = col + dcol[i];
            if(r>=0 && c>=0 && r<n && c<m && grid[r][c]!=0){
                a = max(a, solve(r, c, grid, n, m));
            }
        }
        grid[row][col] = curr;
        return a + curr;
    }
    int getMaximumGold(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int ans = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==0) continue;
                ans = max(ans, solve(i, j, grid, n, m));
            }
        }
        return ans;
    }
};