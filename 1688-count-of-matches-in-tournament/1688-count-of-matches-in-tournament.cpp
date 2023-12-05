class Solution {
public:
    int numberOfMatches(int n) {
        int count = n;
        int matches = 0;
        while(count!=1){
            if(count % 2 == 0 ){
                matches = matches + count/2;
                count = count/2;
            }
            else{
                matches = matches + count/2;
                count = count/2 +1;
            }
        }
        return matches;
    }
};