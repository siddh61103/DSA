class Solution {
public:
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        vector<vector<int>>vec;
        int n = grid.size();
        for(int i=0;i<=n-3;i++){
            vector<int> arr;
            for(int j=0;j<=n-3;j++){
                int k = -1;
                for(int a=0; a<3; a++){
                    for(int b=0 ;b<3; b++){
                        k = max(k,grid[i+a][j+b]);
                    }
                }
                arr.push_back(k);
            }
            vec.push_back(arr);
        }
        return vec;
    }
};