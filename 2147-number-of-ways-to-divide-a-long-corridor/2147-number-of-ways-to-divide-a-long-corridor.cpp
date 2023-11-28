class Solution {
public:
    int numberOfWays(string corridor) {
        int mod = 1000000007;
        vector<int> arr;
        long long ans=1;
        int count = 0;
        for(int i = 0;i < corridor.size() ;i++){
            if(corridor[i]=='S') count++;
        }
        if(count%2!=0 || count==0){
            return 0 ;
        }
        int prev = -1;
        count = 0;
        for(int i = 0;i < corridor.size() ;i++){
            if(corridor[i] =='S'){
                count++;
                if(count ==1 && prev!=-1){
                    int difference = i-prev;
                    ans = ((long long) ans * (long long)difference)%mod;
                }
                if(count ==2){
                    prev = i;
                    count=0;
                }
            }
        }
        
        return ans;
        
    }
};