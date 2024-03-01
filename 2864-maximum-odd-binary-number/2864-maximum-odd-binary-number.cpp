class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int n = s.size();
        int count = 0;
        for(int i =0;i<n;i++){
            if(s[i]=='1'){
                count++;
            }
        }
        s[n-1]='1';
        count--;
        for(int i=0;i<n-1;i++){
            if(count>0){
                s[i]='1';
                count--;
            }
            else{
                s[i]='0';
            }
        }
        return s;
    }
};