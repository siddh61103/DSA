class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        int n = str1.size();
        int m = str2.size();
        vector<vector<int>> dp(n+1, vector<int>(m+1,0));
        for(int i=1; i<n+1; i++){
            for(int j=1; j<m+1; j++){
                if(str1[i-1]==str2[j-1]) dp[i][j] = 1 + dp[i-1][j-1];
                else{
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        int i = n;
        int j = m;
        string b  = "";
        while(i>0 && j>0){
            if(str1[i-1] == str2[j-1]){
                b= b + str1[i-1];
                i--;
                j--;
            }
            else if(dp[i-1][j]>dp[i][j-1]){
                b = b + str1[i-1];
                i--;
            }
            else{
                b = b + str2[j-1];
                j--;
            }
        }
        while(j>0){
            b = b + str2[j-1];
            j--;
        }
        while(i>0){
            b = b + str1[i-1];
            i--;
        }
        reverse(b.begin(),b.end());
        return b;
    }
};