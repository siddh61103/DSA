class Solution {
public:
    string customSortString(string order, string s) {
        string ans = "";
        map<int, char> priority;
        map<char,int> count;
        for(int i=0;i<order.size();i++){
            priority[i] = order[i];
        }
        for(int i=0;i<s.size();i++){
            count[s[i]]++;
        }
        for(auto i : priority){
            char m = i.second;
            int c = count[m];
            while(c!=0){
                ans = ans + m ;
                c--;
            }
            count.erase(m);
        }
        for(auto i :count){
            int c = i.second;
            while(c!=0){
                ans = ans + i.first ;
                c--;
            }
        }
        return ans;
    }
};