class Solution {
public:
    bool is_possible(int n,vector<int> &piles,int hours){
        int count_hour = 0;
        for(int i=0;i<piles.size();i++){
            count_hour += piles[i]/n;
            if(piles[i]%n!=0) count_hour++;
            if(count_hour>hours) return false;
        }
        return true;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        sort(piles.begin(),piles.end());
        int s = 1;
        int e = piles[piles.size()-1];
        while(s<=e){
            int mid = s + (e-s)/2;
            if(is_possible(mid, piles, h)){
                e = mid-1;
            }
            else{
                s = mid+1;
            }
        }
        return s;
    }
};