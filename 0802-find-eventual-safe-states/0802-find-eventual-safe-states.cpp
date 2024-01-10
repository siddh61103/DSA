class Solution {
    bool dfs(int node,vector<int>&vis,vector<vector<int>>& graph){
        vis[node] = 2;
        for(auto it : graph[node]){
            if(vis[it]==0){
                if( dfs(it,vis,graph) ){
                    vis[node] = 3;
                    return true;
                };
            }
            else if(vis[it]==2 ||vis[it]==3){
                vis[node] = 3;
                return true;
            }
        }
        vis[node] = 1;
        return false;
    }
    
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> ans;
        vector<int> vis(n,0);
        for(int i = 0 ;i<n;i++){
            if(vis[i]==0){
                dfs(i,vis,graph);
            }
        }
        for(int i = 0 ;i<n;i++){
            if(vis[i]!=3) ans.push_back(i);
        }
        return ans;
    }
};