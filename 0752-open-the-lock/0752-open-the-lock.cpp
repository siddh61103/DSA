class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        map<string,int> use_map;
        map<string,int> dead_map;
        for(auto i : deadends) dead_map[i]=1;
        queue<pair<string,int>> q;
        if(dead_map.find("0000")!=dead_map.end()) return -1;
        q.push({"0000",0});
        use_map["0000"]=1;
        while(!q.empty()){
            string s = q.front().first;
            int n = q.front().second;
            q.pop();
            if(s==target) return n;
            for(int i=0;i<4;i++){
                string temp = s;
                char c = temp[i];
                //-------------Rotating Wheel Forward--------------//
                if(c=='9') c='0';
                else c++;
                temp[i]=c;
                if(dead_map.find(temp)==dead_map.end() && use_map.find(temp)==use_map.end()){
                    use_map[temp]=1;
                    q.push({temp,n+1});
                }
                //-------------Rotating Wheel Backward--------------//
                temp = s;
                c = temp[i];
                if(c=='0') c='9';
                else c--;
                temp[i]=c;
                if(dead_map.find(temp)==dead_map.end() && use_map.find(temp)==use_map.end()){
                    use_map[temp]=1;
                    q.push({temp,n+1});
                }
            }
        }
        return -1;
    }
};