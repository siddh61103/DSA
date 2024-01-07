class Solution {
public:
    void bfs(int row, int col,vector<vector<int>> &vis,vector<vector<char>>& grid){
        queue<pair<int,int>> q;
        q.push({row,col});
        // if it can move in 8 directions
        // int drow[] = {-1,-1,0,1,1,1,0,-1};
        // int dcol[] = {0, 1, 1,1,0,-1,-1,-1};
        
        // if it can move in 4 directions
        int drow[] = {-1,0,1,0};
        int dcol[] = {0,1,0,-1};
        while(!q.empty()){ 
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            vis[row][col] = 1;
            for(int i=0;i<4;i++){
                int nrow = row + drow[i];
                int ncol = col + dcol[i];
                if(nrow>=0 && nrow<grid.size() && ncol>=0 && ncol<grid[0].size() 
                   && vis[nrow][ncol]==0 && grid[nrow][ncol]=='1'){
                    vis[nrow][ncol]=1;
                    q.push({nrow,ncol});
                }
            }
        }
        return ;
    }
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        int cnt = 0;
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(vis[i][j]==0 && grid[i][j]=='1'){
                    cnt++;
                    bfs(i, j, vis, grid);
                }
            }
        }
        return cnt;
    }
};