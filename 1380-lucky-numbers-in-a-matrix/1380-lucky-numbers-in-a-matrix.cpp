class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        vector<int> row;
        vector<int> ans;
        vector<int> col;
        int n = matrix.size();
        int m = matrix[0].size();
        for(int i=0;i<n;i++){
            int a = 1e9;
            for(int j=0;j<m;j++){
                a = min(a,matrix[i][j]);
            }
            row.push_back(a);
        }
        for(int i=0;i<m;i++){
            int a = -1e9;
            for(int j=0;j<n;j++){
                a = max(a,matrix[j][i]);
            }
            col.push_back(a);
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(row[i]==matrix[i][j] && row[i]==col[j]){
                    ans.push_back(row[i]);
                    break;
                }
            }
        }
        return ans;
    }
};