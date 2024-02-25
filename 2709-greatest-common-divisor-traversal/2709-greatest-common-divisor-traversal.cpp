class Solution {
    void findfactor(int node, int ind, vector<vector<int>> &adj, unordered_map <int,int> &mp){
        for(int j=2; j<=sqrt(node); j++){
            while(node%j==0){
                if(mp.find(j)==mp.end()){
                    mp[j] = ind;
                }
                else{
                    adj[mp[j]].push_back(ind);
                    adj[ind].push_back(mp[j]);
                }
                node = node/j;
            }
        }
        if(node!=1){
            if(mp.find(node)==mp.end()){
                mp[node] = ind;
            }
            else{
                adj[mp[node]].push_back(ind);
                adj[ind].push_back(mp[node]);
            }
        }
        return ;
    }

    void dfs(int node , vector<vector<int>> &adj, vector<int> &vis){
        vis[node] = 1;
        for(auto i : adj[node]){
            if(vis[i]==0){
                dfs(i, adj, vis);
            }
        }
        return;
    }
public:
    bool canTraverseAllPairs(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return true;
        vector<vector<int>> adj(n+1);
        unordered_map <int,int> map;

        for(int i = 0; i<n; i++){
            if(nums[i]==1) return false;

            findfactor(nums[i],i,adj,map);
        }

        vector<int> vis(n,0);
        dfs(0,adj,vis);
        for(auto i : vis){
            if(i==0) return false;
        }
        return true;
    }
};