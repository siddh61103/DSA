class Solution {
public:
    int maximumCandies(vector<int>& candies, long long k) {
        int ans = INT_MIN;
        for(auto i : candies){
            ans = max(i,ans);
        }
        int s = 1;
        int e = ans+1;
        ans = 0;
        while(s<e){
            int mid = s + (e-s)/2;
            long long count = 0;
            for(int i=0;i<candies.size();i++){
                if(mid==0) break;
                count+=candies[i]/mid;
                if(count>=k) break;
            }
            if(count>=k){
                ans = mid;
                s = mid+1;
            }
            else e = mid;
        }
        return ans;
    }
};