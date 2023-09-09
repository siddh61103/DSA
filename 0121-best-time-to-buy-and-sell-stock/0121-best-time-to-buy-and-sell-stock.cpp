class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int prev = prices[0];
        int profit = 0;
        for(int i = 1; i < prices.size() ; i++){
            if( prev > prices[i] ){
                prev = prices[i];
            }
            else if(prev < prices[i]){
                if( profit < ( prices[i] - prev )){
                    profit = prices[i] - prev;
                }
            }
        }
        return profit;
    }
};