class Solution {
public:
    int solve(string s,int k,char a){
        int i=0;
        int j=0;
        int t = 0;
        int ans = 0;
        while(j<s.size()){
            if(s[j]==a){
                j++;
                continue;
            }
            else t++;
            if(t>k){
                ans = max(ans,j-i);
                while(t>k && i<s.size()){
                    if(s[i]!=a) t--;
                    i++;
                }
            }
            j++;
        }
        ans = max(ans,j-i);
        return ans;
    }
    int maxConsecutiveAnswers(string answerKey, int k) {
        int a = solve(answerKey, k,'T');
        int b = solve(answerKey, k,'F');
        return max(a,b);
    }
};