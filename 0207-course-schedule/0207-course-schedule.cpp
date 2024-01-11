class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n = numCourses;
        vector<int> adj[numCourses];
        for(int i = 0;i<prerequisites.size();i++){
            adj[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }
        
        queue<int> q;
        vector<int> indegree(numCourses,0);
        for(int i=0;i<numCourses;i++){
            for(auto j : adj[i]){
                indegree[j]++;
            }
        }
        for(int i=0;i<numCourses;i++){
            if(indegree[i]==0) q.push(i);
        }
        vector<int> ans;
        int cnt = 0;
        while(!q.empty()){
            int n = q.front();
            q.pop();
            cnt++;
            ans.push_back(n);
            for(auto i : adj[n]){
                indegree[i]--;
                if(indegree[i]==0) q.push(i);
            }
        }
        if(cnt == numCourses) return true;
        return false;
    }
};