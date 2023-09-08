class Solution {
public:
    bool isValid(string s) {
        char c = s[0];
        stack<char> temp;
        unordered_map<char,char> check = {{']','['},{')','('},{'}','{'}};
        for(char c :s){
            if(c=='[' || c=='('|| c=='{'){
                temp.push(c);
            }
            else if(temp.empty() || temp.top()!=check[c]){
                return false;
            }
            else{
                temp.pop();
            }
        }
        return temp.empty();
    }
};