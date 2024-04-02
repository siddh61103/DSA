class Solution {
public:
    bool isIsomorphic(string s, string t) {
        map<char,char> mp1;
        map<char,char> mp2;
        for(int i=0;i<s.size();i++){
            if(mp1.find(s[i])!=mp1.end() && mp1[s[i]]!=t[i]) return false; 
            if(mp2.find(t[i])!=mp2.end() && mp2[t[i]]!=s[i]) return false;
            mp2[t[i]] = s[i];
            mp1[s[i]] = t[i];
        }
        return true;
    }
};