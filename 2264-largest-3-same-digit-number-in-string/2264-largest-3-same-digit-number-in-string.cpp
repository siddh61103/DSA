class Solution {
public:
    string largestGoodInteger(string num) {
        int max = 0; 
        string ans = "";
        for(int i = 0; i< num.size()-2;i++){
            string s = num.substr(i,3);
            if(s[0]==s[1] && s[1]==s[2]){
                if(max<=stoi(s)){
                    max = stoi(s);
                    ans = s;
                }
            }
        }
        return ans;
    }
};