class Solution {
public:
    int minInsertions(string s) {
        int n = s.size();
        string m = s;
        reverse(m.begin(),m.end());
        vector<int> dp(n+1,0),curr(n+1,0);

        for(int i=0; i<=n; i++) dp[i] = 0;

        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                if(s[i-1]==m[j-1]) curr[j] = 1 + dp[j-1];
                else curr[j] = max(dp[j],curr[j-1]);
            }
            dp = curr;
        }
        return n-dp[n];
    }
};