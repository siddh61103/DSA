class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;

        int n = grid.size();
        vector<vector<int>> store(n,vector<int>(n,INT_MAX));
        int ans = -1;
        if(grid[0][0]==1) return -1;
        pq.push({1, {0, 0}});
        store[0][0]=1;
        while(!pq.empty()){
            int dis = pq.top().first;
            int row = pq.top().second.first;
            int col = pq.top().second.second;
            pq.pop();
            if(row ==n-1 && col==n-1) {
                ans = dis;
            }
            for(int i=-1; i<=1; i++){
                for(int j=-1; j<=1; j++){
                    int nrow = row + i;
                    int ncol = col + j;
                    if(nrow>=0 && nrow<n && ncol>=0 && ncol<n && store[nrow][ncol]>dis+1 && grid[nrow][ncol]==0){
                        store[nrow][ncol]  = dis+1;
                        pq.push({dis+1, {nrow, ncol}});
                    }
                }
            }
        }
        return ans;;


    }
};