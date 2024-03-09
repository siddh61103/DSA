class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        vector<vector<string>> ans;
        int n = accounts.size();
        map<string,int> mp;
        map<string,vector<string>> graphi;
        for(int i=0;i<n;i++){
            mp[accounts[i][0]]=0;
            for(int j=1;j < accounts[i].size()-1;j++){
                mp[accounts[i][j]]=0;
                mp[accounts[i][j+1]]=0;
                graphi[accounts[i][j]].push_back(accounts[i][j+1]);
                graphi[accounts[i][j+1]].push_back(accounts[i][j]);
            }
        }
        int k = 0;
        for(int i=0;i<n;i++){
            vector<string> temp;
            if(mp[accounts[i][0]]==0){
                temp.push_back(accounts[i][0]);
                mp[accounts[i][0]]=1;
                queue<string> q;
                q.push(accounts[i][1]);
                mp[accounts[i][1]]=1;
                while(!q.empty()){
                    string k = q.front();
                    q.pop();
                    temp.push_back(k);
                    for(auto j : graphi[k]){
                        if(mp[j]==0){
                            mp[j] = 1;
                            q.push(j);
                        }
                    }
                }
                sort(temp.begin()+1,temp.end());
                ans.push_back(temp);
            }
            else{
                int t = -1;
                for(int j=1;j<accounts[i].size();j++){
                    if(mp[accounts[i][j]]==0){
                        t = 1;
                        break;
                    }
                }
                if(t==1){
                    cout<<accounts[i][0]<<endl;
                    temp.push_back(accounts[i][0]);
                    queue<string> q;
                    q.push(accounts[i][1]);
                    mp[accounts[i][1]]=1;
                    while(!q.empty()){
                        string k = q.front();
                        q.pop();
                        temp.push_back(k);
                        for(auto j : graphi[k]){
                            if(mp[j]==0){
                                mp[j] = 1;
                                q.push(j);
                            }
                        }
                    }
                    sort(temp.begin()+1,temp.end());
                    ans.push_back(temp);
                }
            }
        }
        return ans;
    }
};