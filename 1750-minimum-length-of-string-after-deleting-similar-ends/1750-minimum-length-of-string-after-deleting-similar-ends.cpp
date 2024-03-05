class Solution {
public:
    int minimumLength(string s) {
        int i = 0;
        int j = s.size()-1;
        int ans = 0;
        while(i<j){
            char c = s[i];
            char m = s[j];
            if(c!=m) break;
            
            while(s[i]==m && i<=j){
                i++;
            }
            while(s[j]==c && j>=i){
                j--;
            }
            ans++;
        }
        return j-i+1;
    }
};