class Solution {
public:
    int solve(int node,map<int,vector<int>> &mp,int &ans, int &n, long long &sum){
        long long a = 1;
        int b = n;
        int count=0;
        for(auto i:mp[node]){
            int m = solve(i,mp,ans,n,sum);
            a*=m;
            b-=m;
            count+=m;
        }
        if(b<=0) b=1;
        a*=b;
        if(sum==a){
            ans++;
        }
        else if(a>sum){
            ans=1;
            sum=a;
        }
        return count+1;
    }
    int countHighestScoreNodes(vector<int>& parents) {
        map<int,vector<int>> mp;
        int root = 0;
        for(int i=0;i<parents.size();i++){
            mp[parents[i]].push_back(i);
            if(parents[i]==-1) root=i;
        }
        int n = parents.size()-1;
        int ans = 0 ;
        long long sum =0;
        solve(root, mp, ans, n,sum);
        return ans;
    }
};