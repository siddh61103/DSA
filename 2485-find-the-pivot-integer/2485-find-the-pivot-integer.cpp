class Solution {
public:
    int pivotInteger(int n) {
        vector<int> vec(n+1,0);
        int sum = 0;
        for(int i=1;i<=n;i++){
            sum += i;
            vec[i] = sum;
        }
        sum = 0;
        for(int i=n;i>=1;i--){
            sum += i;
            vec[i] = vec[i] - sum;
            if(vec[i]==0) return i;
        }
        return -1;
    }
};