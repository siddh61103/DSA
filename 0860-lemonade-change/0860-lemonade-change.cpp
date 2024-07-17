class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int n = bills.size();
        int a = 0;
        int b = 0;
        int i=0;
        while(i<n){
            if(bills[i]==5) a++;
            else if(bills[i]==10){
                if(a==0) return false;
                a--;
                b++;
            }
            else{
                if(a==0) return false;
                a--;
                if(b==0 && a<2) return false;
                else if(b!=0) b--;
                else a-=2;
            }
            i++;
        }
        return true;
    }
};