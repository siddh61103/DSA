class Solution {
public:
    void pascal(vector<vector<int>> &ans,int n,int a){
        int k = ans.size()-1;
        vector<int> temp;
        if(a==n){
            return ;
        }
        for(int j=0;j<a+1;j++){
            if(j==0 || j==a){
                temp.push_back(1);
            }
            else{
                temp.push_back(ans[k][j-1]+ans[k][j]);
            }
        }
        ans.push_back(temp);
        pascal(ans,n,a+1);
        return;
    }
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        pascal(ans,numRows,0);
        return ans;
    }
};