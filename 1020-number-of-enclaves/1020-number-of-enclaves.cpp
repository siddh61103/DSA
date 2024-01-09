class Solution {
public:
    void dfs(int row, int col, vector<vector<int>>& grid, vector<vector<int>>& vis){
        vis[row][col] = 1;
        int n = grid.size();
        int m = grid[0].size();
        
        int delrow[] = {-1,0,1,0};
        int delcol[] = {0,1,0,-1};
        
        for(int i = 0;i<4;i++){
            int nrow = row + delrow[i];
            int ncol = col + delcol[i];
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m &&
              vis[nrow][ncol]==0 && grid[nrow][ncol] == 1){
                dfs(nrow, ncol, grid, vis);
            }
        }
        return ;
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        
        for(int i = 0;i < m;i++){
            // first row
            if(grid[0][i]==1 && vis[0][i]==0){
                dfs(0,i, grid, vis);
            }
            //last row
            if(grid[n-1][i]==1 && vis[n-1][i]==0){
                dfs(n-1,i, grid ,vis);
            }
        }
        
        for(int i = 0;i < n;i++){
            // first col
            if(grid[i][0]==1 && vis[i][0]==0){
                dfs(i,0, grid, vis);
            }
            
            //last col
            if(grid[i][m-1]==1 && vis[i][m-1]==0){
                dfs(i,m-1, grid ,vis);
            }
        }
        int cnt = 0;
        for(int i=0; i<n;i++){
            for(int j=0; j<m;j++){
                if(vis[i][j]==0 && grid[i][j]==1){
                    cnt++;
                }
            }
        }
        return cnt;
    }
};