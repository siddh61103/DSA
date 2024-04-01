class Solution {
public:
    int lengthOfLastWord(string s) {
        int a = 0;
        int cnt = 0;
        for(int i=s.size()-1;i>=0;i--){
            if(s[i]!=' '){
                a = 1;
                cnt++;
            }
            else if(a==1){
                return cnt;
            }
        }
        return cnt;
    }
};