class Solution {
public:
    int matrixScore(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        for(int i=0;i<n;i++){
            if(grid[i][0]==0){
                for(int j=0;j<m;j++) grid[i][j] ^= 1;
            }
        }        
        for(int j=1;j<m;j++){
            int a = 0;
            int b = 0;
            for(int i=0;i<n;i++){
                if(grid[i][j]==0) a++;
                else b++;
            }
            if(a>b) for(int i=0;i<n;i++) grid[i][j] ^= 1;
        }
        int ans = 0;
        for(int i=0;i<n;i++){
            int a = m-1;
            for(int j=0;j<m;j++){
                if(grid[i][j]==1) ans+=pow(2,a);
                a--;
            }
        }

        return ans;
    }
};