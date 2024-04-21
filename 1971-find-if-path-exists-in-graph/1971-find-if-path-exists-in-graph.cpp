class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>> gp(n);
        for(auto i : edges){
            gp[i[0]].push_back(i[1]);
            gp[i[1]].push_back(i[0]);
        }
        queue<int>q;
        q.push(source);
        vector<int> vis(n,0);
        while(!q.empty()){
            int node = q.front();
            q.pop();
            if(node==destination)  return true;
            for(auto i : gp[node]){
                if(vis[i]==0){
                    vis[i]=1;
                    q.push(i);
                }
            }
        }
        return false;
    }
};