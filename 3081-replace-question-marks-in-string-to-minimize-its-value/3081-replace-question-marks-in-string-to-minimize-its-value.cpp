class Solution {
public:
    string minimizeStringValue(string s) {
        priority_queue<pair<int,char>, vector<pair<int,char>>, greater<pair<int,char>>> pq;
        vector<int> vec(26,0);
        for(auto i: s){
            if(i=='?') continue;
            vec[i-97]++;
        }
        for(int i=0;i<26;i++){
            char m ='a' + i ;
            pq.push({vec[m-97],m});
        }
        string temp = "";
        for(auto i : s){
            if(i!='?'){
                continue;
            }
            int n = pq.top().first;
            char a = pq.top().second;
            pq.pop();
            temp+=a;
            pq.push({n+1,a});
        }
        sort(temp.begin(),temp.end());
        int j = 0;
        string ans = "";
        for(auto i : s){
            if(i!='?'){
                ans+=i;
                continue;
            }
            ans+=temp[j];
            j++;
        }
        return ans;
    }
};