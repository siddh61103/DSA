class Solution {
public:
    int lengthOfLastWord(string s) {
        int i = s.length()-1;
        while(s[i]==' '){
            i--;
        }
        int count = 0;
        while(s[i]!=' '){
            count++;
            if(i==0){
                return count;
            }
            i--;
        }
        return count;
    }
};