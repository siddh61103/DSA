class Solution {
public:
    int reverse(int x) {
        long long int n =x;
        if(x<0){
            n = n*(-1);
        }
        long long int ans = 0;
        while(n>0){
            ans = ( ans * 10 )+( n % 10 );
            n = n/10;
        }
        if(ans>pow(-2,21) && ans<pow(2,31)-1){
        }
        else{
            return 0;
        }
        if(x<0){
            return ans*-1;
        }
        return ans;
        
    }
};