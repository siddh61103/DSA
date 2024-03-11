class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char,int> mp;
        int i = 0;
        int j = 0;
        int ans = 0;
        int count = 0;
        while(j<s.size()){
            if(mp.find(s[j])==mp.end()){
                mp[s[j]] = j;
                count++;
                j++;
            }
            else{
                while(i<=mp[s[j]]){
                    mp.erase(s[i]);
                    count--;
                    i++;
                }
                mp[s[j]]=j;
                count+=1;
                j++;
            }
            ans = max(ans,count);
        }
        return ans;
    }
};