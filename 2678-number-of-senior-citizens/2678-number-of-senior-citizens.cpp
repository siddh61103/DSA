class Solution {
public:
    int countSeniors(vector<string>& details) {
        int ans = 0;
        for(auto i : details){
            string m ;
            m+=i[11];
            m+=i[12];
            if(stoi(m)>60) ans++;
        }
        return ans;
    }
};