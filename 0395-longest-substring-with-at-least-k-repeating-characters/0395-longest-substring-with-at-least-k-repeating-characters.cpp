class Solution {
public:
    int longestSubstring(string s, int k) {
        int n = s.size();
        set<char> seti;
        for(int i=0;i<n;i++){
            seti.insert(s[i]);
        }
        int un = seti.size();
        int ans = 0;
        for(int p=1;p<=un;p++){
            int i=0;
            int j=0;
            int uniKTime = 0;
            int curUni = 0;
            vector<int> vec(26,0);
            while(j<n){
                if(curUni<=p){
                    // Expand
                    int m = s[j]-'a';
                    if(vec[m]==0){
                        curUni++;
                    }
                    vec[m]++;
                    if(vec[m]==k) uniKTime++;
                    j++;
                }
                else{
                    int m = s[i]-'a';
                    // Short
                    if(vec[m]==k) uniKTime--;
                    vec[m]--;
                    if(vec[m]==0) curUni--;
                    i++;
                }
                if(uniKTime==p && curUni==p){
                    ans = max(ans,j-i);
                }
            }
        }
        return ans;
    }
};