class Solution {
public:
    
    void dfs(int n, vector<int> &vis,vector<vector<int>>& isConnected){
        vis[n]=1;
        for(int i = 0; i<isConnected[0].size();i++){
            if(!vis[i] && isConnected[n][i]==1){
                dfs(i, vis, isConnected);
            }
        }
        return;
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int> vis(n,0);
        int ans = 0;
        for(int i = 0 ;i<n; i++){
            cout<<i<<" ";
            if(vis[i]==0){
                dfs(i, vis, isConnected);
                ans++;
            }
        }
        return ans;
    }
};