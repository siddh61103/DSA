class Solution {
public:
    void dfs(int node , vector<vector<pair<int,int>>> &vec, vector<int> &vis, int &a, int t, int s){
        if(t%s==0) a++;
        vis[node]=1;
        for(auto i : vec[node]){
            int h = i.first;
            int d = i.second;
            if(vis[h]==0){
                dfs(h,vec,vis,a,t+d,s);
            }
        }
        return ;
    }
    
    vector<int> countPairsOfConnectableServers(vector<vector<int>>& edges, int s) {
        int max = 0;
        for(auto i : edges){
            if(i[0]>max) max = i[0];
            if(i[1]>max) max = i[1];
        }
        int n = max+1;
        vector<int> ans(max+1,0);
        
        vector<vector<pair<int,int>>> vec(max+1);
        
        for(auto i : edges){
            vec[i[0]].push_back({i[1],i[2]});
            vec[i[1]].push_back({i[0],i[2]});
        }
        for(int i = 0;i < n; i++){
            if(vec[i].size()<=1){
                ans[i]=0;
                continue;
            }
            vector<int> temp;
            vector<int> vis(n,0);
            vis[i]=1;
            for(auto j : vec[i]){
                int h = j.first;
                int d = j.second;
                int a = 0;
                if(vis[h]==0){
                    dfs(h,vec,vis,a,d,s);
                    temp.push_back(a);
                }
            }
            int x = 0;
            for(int k = 0;k<temp.size();k++ ){
                for(int m = k+1;m<temp.size();m++ ){
                    x = x + (temp[k]*temp[m]);
                }
            }
            ans[i] = x;
        }
        
        return ans;
    }
};