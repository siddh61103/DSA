class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        // int arr[mat.size()]={0};
        vector<int> ans;
        for(int i = 0; i < mat.size();i++){
            int count = 0 ;
            for(int j = 0; j < mat[0].size(); j++){
                if(mat[i][j]==1){
                    count++;
                }
            }
            ans.push_back(count);
        }
        for(int i = 0; i  < mat.size();i++){
            cout<< ans[i]<<" ";
        }
        vector<int> arr;
        for(int i = 0;i < k;i++){
            int k = 0;
            int min = INT_MAX;
            for(int j = 0;j < ans.size(); j++){
                if( min > ans[j] ){
                    k = j;
                    min = ans[j];
                }
            }
            ans[k] = INT_MAX;
            arr.push_back(k);
        }
        return arr;
    }
};