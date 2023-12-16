class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> arr(26,0);
        
        if(s.size()!=t.size()) return false ;
        
        for(int i=0; i<s.size();i++){
            arr[s[i]-97]++;
            arr[t[i]-97]--;
        }
        
        for(auto i : arr){
            cout<<i<<" ";
            if(i!=0){
                return false;
            }
        }
        return true;
    }
};