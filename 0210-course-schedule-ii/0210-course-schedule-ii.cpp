class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        
        vector<int> adj[numCourses];
        
        for(int i =0;i<prerequisites.size();i++){
            adj[ prerequisites[i][1] ].push_back( prerequisites[i][0] );
        }
        
        vector<int> indegree(numCourses,0);
        
        for(int i = 0;i<numCourses;i++){
            for(auto j : adj[i]){
                indegree[j]++;
            }
        }
        
        queue<int> q;
        for(int i =0;i<numCourses;i++){
            if(indegree[i]==0) q.push(i);
        }
        
        vector<int>ans;
        
        while(!q.empty()){
            int n = q.front();
            q.pop();
            ans.push_back(n);
            for(auto i : adj[n]){
                indegree[i]--;
                if(indegree[i]==0) q.push(i);
            }
        }
        
        if(ans.size()==numCourses) return ans;
        return {};
        
        
    }
};