class Solution {
public:
    int maximumGain(string s, int x, int y) {
        string a = "ab";
        string b = "ba";
        if(x<y) swap(a,b);
        int ans=0;
        string t = "";
        int i=0;
        while(i<s.size()){
            if(s[i]==a[1] && t.size()!=0 && t[t.size()-1]==a[0]){
                string m = "";
                m=t[t.size()-1];
                m+=s[i];
                if(m=="ab") ans+=x;
                else ans+=y;
                t.pop_back();
            }
            else{
                t+=s[i];
            }
            i++;
        }
        i=0;
        s=t;
        t="";
        while(i<s.size()){
            if(s[i]==b[1] && t.size()!=0 && t[t.size()-1]==b[0]){
                string m = "";
                m=t[t.size()-1];
                m+=s[i];
                if(m=="ab") ans+=x;
                else ans+=y;
                t.pop_back();
            }
            else{
                t+=s[i];
            }
            i++;
        }
        return ans;
    }
};