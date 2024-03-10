class Solution {
public:
    vector<string> shortestSubstrings(vector<string>& arr) {
        
        int n = arr.size();
        vector<string> ans(n,"");
        map<string,int> mp;
        map<string,set<string>> temp;
        
        for(int j=0;j<n;j++){
            string s = arr[j];
            set<string> set;
            for(int i=0;i<s.size();i++){
                for(int k=1;k<=s.size()-i;k++){
                    string m = s.substr(i,k);
                    set.insert(m);
                    if(mp.find(m)==mp.end()){
                        mp[m]=j;
                    }
                    else if(mp[m]!=j){
                        mp[m]= 102;
                    }
                }
            }
            temp[s] = set;
        }
        for(int j=0;j<n;j++){
            string s = arr[j];
            string k = s;
            for(auto i : temp[s]){
                if(mp[i]==j){
                    if(k.size() > i.size()){
                        k =i;
                    }
                }
            }
            if(k==s){
                if(mp[k]!=j) k ="";
            }
            ans[j] = k;
        }
        return ans;
    }
};