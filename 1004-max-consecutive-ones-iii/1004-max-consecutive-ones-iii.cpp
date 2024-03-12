class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        queue<int> q;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0) q.push(i);
        }
        int count = 0;
        int ans = 0;
        int i = 0;
        int j = 0;
        while(j<nums.size()){
            if(nums[j]==1){
                count++;
                j++;
            }
            else{
                if(k!=0){
                    count++;
                    j++;
                    k--;
                }
                else{
                    int m = q.front();
                    q.pop();
                    while(i<=m){
                        count--;
                        i++;
                    }
                    count = j-i+1;
                    j++;
                }
            }
            ans = max(ans, count);
        }
        return ans;
    }
};