class Solution {
public:
    vector<int>s;
    void solve(int n,int ans){
        if(ans>n){
            return ;
        }
        else{
            s.push_back(ans);
        }
        for(int i=0;i<=9;i++){
            solve(n,(ans*10)+i);
        }
        return;
    }
    vector<int> lexicalOrder(int n) {
        for(int i=1;i<=9;i++){
                solve(n,i);
        }
        return s;
    }
};