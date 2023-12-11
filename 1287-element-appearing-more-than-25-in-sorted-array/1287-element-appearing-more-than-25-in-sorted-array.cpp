class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        vector<int> v(1000000,0);
        for(int i =0;i<arr.size();i++){
            v[arr[i]]++;
        }
        for(int i =0;i<v.size();i++){
            if(v[i] > arr.size()/4){
                return i;
            }
        }
        return -1;
        
    }
};