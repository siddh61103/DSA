class Solution {
public:
    string reverse(int i, int j, string &s){
        while(i<j){
            char temp = s[i];
            s[i] = s[j];
            s[j] = temp;
            i++;
            j--;
        }
        return s;
    }
    string reverseParentheses(string s) {
        int i=0;
        stack<int> stack;
        while(i<s.size()){
            if(s[i]==')') break;
            if(s[i]=='(') stack.push(i);
            i++;
        }
        if(stack.empty()) return s;
        int j = stack.top() + 1;
        while(j<s.size()){
            if(s[j]=='(') stack.push(j);
            else if(s[j]==')') {
                reverse(stack.top(),j,s);
                stack.pop();
            }
            j++;
        }
        s.erase(remove(s.begin(),s.end(),'('),s.end());
        s.erase(remove(s.begin(),s.end(),')'),s.end());
        return s;
    }
};