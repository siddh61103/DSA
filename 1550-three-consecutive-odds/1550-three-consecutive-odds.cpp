class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int n = arr.size();
        if(n<3) return 0;
        int i = 0;
        int j = 1;
        int k = 2;
        while(k<n){
            if(arr[i]%2!=0 && arr[j]%2!=0 && arr[k]%2!=0) return 1;
            i++;
            j++;
            k++;
        }
        return 0;
    }
};