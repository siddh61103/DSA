class Solution {
public:
    bool is_possible(int n, vector<int>& bloomDay, int m,int k){
        int ans = 0;
        int h = 0;
        for(int i=0;i<bloomDay.size();i++){
            if(bloomDay[i]<=n){
                h++;
            }
            else{
                h=0;
            }
            if(h==k){
                h=0;
                ans++;
            }
            if(ans>=m) return true;
        }
        return false;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int s = 0;
        int e = 0;
        int maxi = 0;
        for(int i=0;i<bloomDay.size();i++){
            s = min(s,bloomDay[i]);
            e = max(e,bloomDay[i]);
            maxi = e;
        }
        int ans = INT_MAX;
        while(s<=e){
            int mid = s + (e-s)/2;
            if(is_possible(mid,bloomDay, m, k)){
                e = mid-1;
            }
            else{
                s = mid+1;
            }
        }
        if(s>maxi) return -1;
        return s;
    }
};