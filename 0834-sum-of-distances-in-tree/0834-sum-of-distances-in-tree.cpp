class Solution {
public:
    void ans_dfs(int node, vector<int>&store,vector<vector<int>> &gp, vector<int>&vis ,vector<int> &ans){
        for(auto i: gp[node]){
            if(vis[i]==0){
                vis[i]=1;
                ans[i] = ans[node] -  store[i] + (gp.size()-store[i]);
                ans_dfs(i,store, gp, vis, ans);
            }
        }
        return ;
    }
    int dfs(int node,vector<vector<int>>&gp,vector<int>&vis,vector<int>&store, int d, int &rootsum ){
        int a = 0;
        for(auto i : gp[node]){
            if(vis[i]==0){
                vis[i]=1;
                a+=dfs(i,gp,vis,store,d+1,rootsum);
            }
        }
        rootsum+=d;
        store[node]=a+1;
        return 1+a;
    }
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> gp(n);
        vector<int> ans(n,0);
        for(auto i: edges){
            gp[i[0]].push_back(i[1]);
            gp[i[1]].push_back(i[0]);
        }
        int rootsum = 0;
        vector<int> vis(n,0);
        vector<int> store(n,0);
        vis[0]=1;
        dfs(0, gp, vis, store,0,rootsum);
        for(int i=1;i<n;i++) vis[i]=0;
        ans[0] = rootsum;
        ans_dfs(0,store,gp,vis,ans);
        return ans;
    }
};
//--I am using vector store for storing number of node in every sub tree;
//Doing rerouting taking help of my parent node