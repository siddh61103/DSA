class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<pair<int,int>> adj[n];
        for(auto it : flights){
            adj[it[0]].push_back({it[1],it[2]});
        }
        queue<pair<int,pair<int,int>>> q;
        vector<int> vec(n,INT_MAX);
        q.push({0, {0,src}});
        vec[src]= 0 ;
        while(!q.empty()){
            int step = q.front().first;
            int dis = q.front().second.first;
            int node = q.front().second.second;
            q.pop();

            if(step > k) continue;
            for(auto i : adj[node]){
                int newnode = i.first;
                int newdis = i.second + dis;
                if(vec[newnode] > newdis && step <= k){
                    vec[newnode] = newdis;
                    q.push({step+1,{newdis,newnode}});
                }
            }
        }
        if(vec[dst] == INT_MAX) vec[dst] = -1;
        return vec[dst];
    }
};