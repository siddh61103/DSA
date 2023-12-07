class Solution {
public:
    string largestOddNumber(string num) {
        
        for(int i = num.size(); i>=0;i--){
            int m = int(num[i]);
            if(m%2!=0){
                return num.substr(0,i+1);
            }
        }
        return "";
    }
};