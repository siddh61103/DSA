class Solution {
public:
    int maxi(map<char,int> mp){
        int a = 0 ;
        for(auto i : mp){
            a = max(a,i.second);
        }
        return a;
    }
    int characterReplacement(string s, int k) {
        map<char,int> mp;
        int n = s.size();
        int ans = 0;
        int i=0;
        int j=0;
        while(j<n){
            mp[s[j]]++;
            int m = maxi(mp);
            if(j - i  + 1 - m <= k ){
                cout<<ans<<" "<<j<<" "<<m<<endl;
                ans = max(ans, j-i+1);
                j++;
            }
            else{
                mp[s[i]]--;
                i++;
                j++;
            }
        }
        return ans;
    }
};