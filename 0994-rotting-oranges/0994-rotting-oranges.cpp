class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        //{{r,c},time}
        // vector<vector<int>> vis(n,vector<int>(m,0));
        int vis[n][m];
        int cntfresh = 0 ;
        queue<pair<pair<int,int>,int>> q;
        for(int i=0; i<n; i++){
            for(int j = 0; j<m; j++){
                if( grid[i][j]==2 ){
                    vis[i][j] = 2;
                    q.push({{i, j}, 0});
                }
                else{
                    vis[i][j]=0;
                }
                if( grid[i][j]==1 ) {
                    cntfresh++;
                }
            }
        }
        
        int ans = 0;
        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, 1, 0 ,-1};
        int cnt = 0;
        while(!q.empty()){
            int r = q.front().first.first;
            int c = q.front().first.second;
            int t = q.front().second;
            ans = t;
            q.pop();
            for(int i = 0; i<4; i++){
                int nrow = r + drow[i];
                int ncol = c + dcol[i];
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m &&
                   vis[nrow][ncol]!=2 && grid[nrow][ncol]!=0){
                    q.push({{nrow, ncol}, t+1});
                    vis[nrow][ncol] = 2;
                    cnt++;
                }
            }
        }
        if(cnt!=cntfresh) ans = -1;
        return ans;
    }
};