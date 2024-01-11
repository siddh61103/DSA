class Solution {
    
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int>> adj(n);
        for(int i =0;i<graph.size();i++){
            for(auto it : graph[i]){
                adj[it].push_back(i);
            }
        }
        graph = adj;
        vector<int> indegree(n,0);
        
        for(int i = 0;i<n;i++){
            for(auto j : graph[i]){
                indegree[j]++;
            }
        }
        
        queue<int> q;
        for(int i =0;i<n;i++){
            if(indegree[i]==0) q.push(i);
        }
        
        vector<int>ans;
        
        while(!q.empty()){
            int node = q.front();
            q.pop();
            ans.push_back(node);
            for(auto i : graph[node]){
                indegree[i]--;
                if(indegree[i]==0) q.push(i);
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
        
    }
};