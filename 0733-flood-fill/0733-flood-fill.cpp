class Solution {
public:
    void dfs(int row,int col,vector<vector<int>>& image,int color,int prevcolor){
        image[row][col]=color;
        int delrow[] = {-1,0,1,0};
        int delcol[] = {0,1,0,-1};
        for(int i=0;i < 4;i++){
            int nrow = row + delrow[i];
            int ncol = col + delcol[i];
            if(nrow>=0 && nrow<image.size() && ncol>=0 && ncol<image[0].size() &&
               image[nrow][ncol]!=color && image[nrow][ncol]==prevcolor){
                dfs(nrow, ncol, image, color, prevcolor);
            }
        }
        return ;
        
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int prevcolor = image[sr][sc];
        dfs(sr,sc,image,color,prevcolor);
        return image;
    }
};