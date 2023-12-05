class Solution {
public:
    int numberOfMatches(int n) {
        int count = n;
        int matches = 0;
        while(count!=1){
            matches = matches + count/2;
            count = count/2 + count%2;
        }
        return matches;
    }
};