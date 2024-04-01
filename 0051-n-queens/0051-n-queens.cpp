class Solution {
public:
    bool is_safe(int col, int row, vector<string> &vec){
        int n = vec.size();
        int i = row;
        int j = col;
        //horizontally
        while(j>=0){
            if(vec[i][j]=='Q') return false;
            j--;
        }

        //upper diagonal
        j = col;
        while(j>=0 && i>=0){
            if(vec[i][j]=='Q') return false;
            i--;
            j--;
        }
        i=row;
        j=col;
        //lower diagonal
        while(j>=0 && i<n){
            if(vec[i][j]=='Q') return false;
            i++;
            j--;
        }
        return true;
    }
     void solve( int col, vector<string> &vec, vector<vector<string>> &ans,int n){
        if(col==n) {
            ans.push_back(vec);
            return ;
        }
        for(int i=0;i<n;i++){
            if(is_safe(col,i,vec)){
                vec[i][col] = 'Q';
                solve(col+1,vec,ans,n);
                vec[i][col] = '.';
            }
        }
        return ;
     }



    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> vec;
        string s;
        for(int i=0;i<n;i++) s+='.';
        for(int i=0;i<n;i++) vec.push_back(s);
        solve(0,vec,ans,n);
        return ans;
    }

};