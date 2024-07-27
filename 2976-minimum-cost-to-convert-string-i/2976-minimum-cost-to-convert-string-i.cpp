class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        vector<vector<long long>> vec(26,vector<long long>(26,1e18));
        for(int i=0;i<original.size();i++){
            int a = original[i]-'a';
            int b = changed[i]-'a';
            vec[a][b] = min(vec[a][b],(long long) cost[i]);
        }
        for(int i=0;i<26;i++) vec[i][i]=0;
        for(int i=0;i<26;i++){
            for(int j=0;j<26;j++){
                for(int k=0;k<26;k++){
                    vec[j][k] = min(vec[j][k],vec[j][i]+vec[i][k]);
                }
            }
        }
        long long ans = 0;
        for(int i=0;i<source.size();i++){
            int a = source[i]-'a';
            int b = target[i]-'a';
            if(a==b) continue;
            if(vec[a][b]>=1e18) return -1;
            ans +=vec[a][b];
        }
        return ans;
    }
};