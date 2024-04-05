class Solution {
public:
    string makeGood(string s) {
        stack<char> stack;
        for(int i=0;i<s.size();i++){
            stack.push(s[i]);
        }
        string a = "";
        a+=stack.top();
        stack.pop();
        while(!stack.empty()){
            int n = a.size()-1;
            if(n==-1){
                a+=stack.top();
                stack.pop();
                n=0;
            }
            if(stack.empty()) break;
            if(a[n]>='a' && a[n]<='z'){
                if(stack.top()==a[n]-32){
                    a.erase(n);
                }
                else{
                    a+=stack.top();
                }
            }
            else{
                if(stack.top()==a[n]+32){
                    a.erase(n);
                }
                else{
                    a+=stack.top();
                }
            }
            stack.pop();
        }
        reverse(a.begin(),a.end());
        return a;
    }
};