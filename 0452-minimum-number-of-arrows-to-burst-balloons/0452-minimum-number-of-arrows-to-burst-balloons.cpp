class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(),points.end());
        vector<vector<int>> vec;
        vec.push_back(points[0]);
        for(int i=1;i<points.size();i++){
            if(vec.back()[1]<points[i][0]){
                vec.push_back(points[i]);
                continue;
            }
            vec.back()[1] = min(vec.back()[1],points[i][1]);
        }
        return vec.size();
    }
};