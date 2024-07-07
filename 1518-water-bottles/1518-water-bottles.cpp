class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int full=numBottles;
        int empty = 0;
        int ans = 0;
        int k = numExchange;
        while(full!=0){
            ans+=full;
            empty+=full;
            full = empty/k;
            empty = empty%k;
        }
        return ans;
    }
};