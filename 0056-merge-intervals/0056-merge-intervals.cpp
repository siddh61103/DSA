class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        int n = intervals.size();
        vector<vector<int>> ans;
        ans.push_back(intervals[0]);
        for(int i=1;i<n;i++){
            if(intervals[i][0]<=ans.back()[1]){
                ans.back()[1] = std::max(intervals[i][1],ans.back()[1]);
                continue;
            }
            ans.push_back(intervals[i]);
        }
        return ans;
    }
};