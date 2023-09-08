class Solution {
public:
    int reverse(int x) {
        int ans =0;
        while(x){
            if(ans>INT_MAX/10 ||ans<INT_MIN/10) return false;
            ans = ans * 10 +( x % 10 );
            x = x / 10;
        }
        return ans;
        
    }
};