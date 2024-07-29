class Solution {
public:
    int solve(int i, int c, int p, bool check, vector<int> & rating,vector<vector<vector<int>>> &dp){
        if(c==3) return 1;
        if(i==rating.size()) return 0;
        if(p!=-1 && dp[i][p][c]!=-1) return dp[i][p][c];
        int a = 0;
        int b = 0;
        a = solve(i+1,c,p,check,rating,dp);
        if(check){
            if(p==-1 || rating[i]<rating[p]) b = solve(i+1,c+1,i,check,rating,dp);
        }
        else{
            if(p==-1 || rating[i]>rating[p]) b = solve(i+1,c+1,i,check,rating,dp);
        }
        if(p!=-1) dp[i][p][c] = a+b;
        return a+b;
    }
    int numTeams(vector<int>& rating) {
        int n = rating.size();
        vector<vector<vector<int>>> dp(n+4, vector<vector<int>>(n+4, vector<int>(4, -1)));
        int ans = solve(0,0,-1,1,rating,dp);
        dp.assign(n+4, vector<vector<int>>(n+4, vector<int>(4, -1)));
        ans +=solve(0,0,-1,0,rating,dp);
        return ans;
    }
};