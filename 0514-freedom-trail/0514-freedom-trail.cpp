class Solution {
public:
    int findRotateSteps(string ring, string key) {
        int n = ring.size();
        int m = key.size();
        int a,b;
        queue< tuple<int, int ,int> >q;
        vector<vector<int>> vis(n+99, vector<int>(m+99,0));
        q.push({0,0,0});
        vis[0][0] = 1;
        while(!q.empty()){
            auto[r,k,steps] = q.front();
            q.pop();
            if(k==key.size()) return steps;

            if(ring[r]==key[k]){
                if(vis[r][k+1]==0){
                    q.push({r, k+1, steps+1});
                    vis[r][k+1]=1;
                }
                continue;
            }
            a = r-1;
            b = r+1;
            if(r==0) a=n-1;
            if(r==n-1) b=0;
            if(ring[a]==key[k]){
                if(vis[a][k+1]==0){
                    q.push({a, k+1, steps+2});
                    vis[a][k+1]=1;
                }
            }
            else{
                if(vis[a][k]==0){
                    q.push({a, k, steps+1});
                    vis[a][k]=1;
                }
            }
            if(ring[b]==key[k]){
                if(vis[b][k+1]==0){
                    q.push({b, k+1, steps+2});
                    vis[b][k+1]=1;
                }
            }
            else{
                if(vis[b][k]==0){
                    q.push({b, k, steps+1});
                    vis[b][k]=1;
                }
            }
        }
        return 0;
    }
};