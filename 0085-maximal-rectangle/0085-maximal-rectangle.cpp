class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> left;
        vector<int> right;
        stack<pair<int,int>> l ;
        stack<pair<int,int>> r ;
        for(int i = 0;i < n; i++){
            if(l.size()==0){
                left.push_back(-1);
            }
            if(l.size()>0 && l.top().first < heights[i]){
                left.push_back(l.top().second);
            }
            if(l.size()>0 && l.top().first >= heights[i]){
                while(l.size()>0 && l.top().first >= heights[i]){
                    l.pop();
                }
                if(l.size()==0){
                    left.push_back(-1);
                }
                else{
                    left.push_back(l.top().second);
                }
            }
            l.push({heights[i],i});
        }
        for(int i = n-1;i >=0; i--){
            if(r.size()==0){
                right.push_back(n);
            }
            if(r.size()>0 && r.top().first < heights[i]){
                right.push_back(r.top().second);
            }
            if(r.size()>0 && r.top().first >= heights[i]){
                while(r.size()>0 && r.top().first >= heights[i]){
                    r.pop();
                }
                if(r.size()==0){
                    right.push_back(n);
                }
                else{
                    right.push_back(r.top().second);
                }
            }
            r.push({heights[i],i});
        }
        reverse(right.begin(),right.end());
        int ans= 0;
        for(int i =0 ;i<n;i++){
            int k = (heights[i]) * (right[i]-left[i]-1);
            if(ans<k){
                ans = k;
            }
        }
        return ans;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix[0].size();
        int ans = 0;
        vector<int> s (n, 0);
        for(int i = 0 ;i <matrix.size();i++){
            for(int j = 0;j < n;j++){
                if(matrix[i][j]=='0'){
                    s[j]=0;
                }
                else{
                    s[j]++;
                }
            }
            int h = largestRectangleArea(s);
            if(ans<h){
                ans = h;
            }
        }
        return ans;
    }
};