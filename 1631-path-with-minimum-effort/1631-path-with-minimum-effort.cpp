class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        vector<vector<int>> store(n,vector<int>(m,INT_MAX));
        priority_queue<pair<int,pair<int,int>>,
        vector<pair<int,pair<int,int>>>,
        greater<pair<int,pair<int,int>>>> pq;

        int delrow[] = {-1,0,1,0};
        int delcol[] = {0,1,0,-1};
        pq.push({0,{0,0}});
        store[0][0]=0;

        while(!pq.empty()){
            int jump = pq.top().first;
            int row = pq.top().second.first;
            int col = pq.top().second.second;
            pq.pop();
            if(row==n-1 && col ==m-1) return jump;
            for(int i=0; i < 4; i++){
                int nrow = row + delrow[i];
                int ncol = col + delcol[i];
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m){
                    int newjump = max(abs(heights[nrow][ncol] - heights[row][col]),jump);
                    if(store[nrow][ncol] > newjump){
                        store[nrow][ncol] = newjump;
                        pq.push({newjump, {nrow,ncol}});
                    }
                }
            }
        }
        return 0;
    }
};