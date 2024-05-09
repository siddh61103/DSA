class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        sort(happiness.begin(),happiness.end());
        long long ans = 0;
        int c = 0;
        int i = happiness.size()-1;
        while(c<k && i>=0){
            if(happiness[i]-c<=0) break;
            ans+= happiness[i] - c;
            i--;
            c++;
        }
        return ans;
    }
};