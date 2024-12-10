class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int r = matrix.size();
        int c = matrix[0].size();
        int n = 1;
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(matrix[i][j]==0){
                    if(j==0) n=0;
                    else matrix[0][j]=0;
                    matrix[i][0]=0;
                }
            }
        }
        for(int i=1;i<r;i++){
            for(int j=1;j<c;j++){
                if(matrix[0][j]==0 || matrix[i][0]==0) matrix[i][j]=0;
            }
        }
        for(int j=c-1;j>=0;j--){
            if (matrix[0][0]==0 ) matrix[0][j]=0;
        }
        for(int i=0;i<r;i++){
            if (n==0 ) matrix[i][0]=0;
        }
        return ;
    }
};