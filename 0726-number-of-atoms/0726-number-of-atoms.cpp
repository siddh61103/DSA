class Solution {
public:
    string countOfAtoms(string formula) {
        int n = formula.size();
        map<string, int> mp;
        stack<string> s1;
        for(int i=0;i<n;i++){
            string a = "";
            if(formula[i]==')'||formula[i]=='('){
                a += formula[i];
                s1.push(a);
            }
            else if((formula[i]>='0' && formula[i]<='9')){
                a+=formula[i];
                i++;
                while(i<n && formula[i]>='0' && formula[i]<='9'){
                    a+=formula[i];
                    i++;
                }
                if(i!=n) i--;
                s1.push(a);
            }
            else{
                a = formula[i];
                if(i<n-1 && formula[i+1]>='a' && formula[i+1]<='z'){
                    a+=formula[i+1];
                    i++;
                }
                s1.push(a);
                if(i<n-1 && (formula[i+1]<'0' || formula[i+1]>'9')) s1.push("1");
            }
        }
        if((formula[n-1]<'0' || formula[n-1]>'9') && formula[n-1]!='(' && formula[n-1]!=')' ) s1.push("1");
        stack<string> s2;
        while(!s1.empty()){
            queue<string> q;
            if(s1.top()=="("){
                s1.pop();
                while(s2.top()!=")"){
                    q.push(s2.top());
                    s2.pop();
                }
                s2.pop();
                string a ="";
                if(s2.size()!=0) a = s2.top();
                if((a[0]>='0' && a[0]<='9')){
                    s2.pop();
                    int m = stoi(a);
                    while(!q.empty()){
                        string b = q.front();
                        if(b[0]>='0'&& b[0]<='9'){
                            int k = stoi(b);
                            s1.push(to_string(k*m));
                        }
                        else{
                            s1.push(q.front());
                        }
                        q.pop();
                    }
                }
                else{
                    while(!q.empty()){
                        s1.push(q.front());
                        q.pop();
                    }
                }
            }
            else{
                s2.push(s1.top());
                s1.pop();
            }
        }
        while(!s2.empty()){
            string a = s2.top();
            s2.pop();
            int b = stoi(s2.top());
            s2.pop();
            mp[a]+=b;
        }
        string ans = "";
        for(auto i: mp){
            ans+=i.first;
            if(i.second>1){
                ans+=to_string(i.second);
            }
        }
        return ans;
    }
};