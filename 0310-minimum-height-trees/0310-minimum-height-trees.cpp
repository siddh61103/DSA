class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n<=0) return {};
        if(n==1) return {0};
        vector<int> ans;
        vector<vector<int>> gp(n);
        vector<int>degree(n,0);
        for(auto i: edges){
            degree[i[1]]++;
            degree[i[0]]++;
            gp[i[0]].push_back(i[1]);
            gp[i[1]].push_back(i[0]);
        }
        queue<int> q;
        for(int i=0;i<degree.size();i++){
            if(degree[i]==1) q.push(i);
        }
        while(n>2){
            int size = q.size();
            n = n - size;
            while(size-->0){
                int node = q.front();
                q.pop();
                for(auto i : gp[node]){
                    degree[i]--;
                    if(degree[i]==1) q.push(i);
                }
            }
        }
        while(!q.empty()){
            ans.push_back(q.front());
            q.pop();
        }
        return ans;
    }
};