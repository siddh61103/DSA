class Solution {
public:
    int solve(int c,vector<vector<int>>& grid,int prev, vector<vector<int>> &dp){
        if(c==grid[0].size()){
            return 0;
        }
        vector<int> vec(10,0);
        int row = grid.size();
        for(int i=0;i<row;i++){
            vec[grid[i][c]]++;
        }

        int k = INT_MAX;
        for(int i=0;i<=9;i++){
            int a = row-vec[i];
            if(i!=prev){
                if(dp[c][i]==-1){
                    dp[c][i] = a + solve(c+1,grid,i,dp);
                }
                k = min(dp[c][i],k);
            }
        }
        return k;
    }
    int minimumOperations(vector<vector<int>>& grid) {
        int c = grid[0].size();
        vector<vector<int>> dp(c+1, vector<int> (10,-1));
        return solve(0,grid,-1,dp);
    }
};