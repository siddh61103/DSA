class Solution {
public:
    vector<int> dj(int s, vector<vector<pair<int,int>>> &gp){
        priority_queue <pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        vector<int> vis(gp.size(),1e9);
        pq.push({0,s});
        vis[s]=0;
        while(!pq.empty()){
            int d = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            if(d > vis[node]) continue;
            for(auto i: gp[node]){
                int n = i.first;
                int sum = d + i.second;
                if(vis[n]>sum){
                    vis[n] = sum;
                    pq.push({sum,n});
                }
            }
        }
        return vis;
    }
    vector<bool> findAnswer(int n, vector<vector<int>>& edges) {
        vector<bool> ans(edges.size());
        vector<vector<pair<int,int>>> gp(n);
        for(auto i : edges){
            gp[i[0]].push_back({i[1],i[2]});
            gp[i[1]].push_back({i[0],i[2]});
        }
        vector<int> gvis1 = dj(0,gp);
        vector<int> gvis2 = dj(n-1,gp);
        int h = gvis2[0];
        if(h==1e9) return ans;
        for(int i=0;i<edges.size();i++){
            int a = edges[i][2];
            int b = edges[i][2];
            a+= gvis1[edges[i][0]] + gvis2[edges[i][1]];
            b+= gvis1[edges[i][1]] + gvis2[edges[i][0]];
            if(a==h || b==h) ans[i]=true;
        }
        return ans;
    }
};