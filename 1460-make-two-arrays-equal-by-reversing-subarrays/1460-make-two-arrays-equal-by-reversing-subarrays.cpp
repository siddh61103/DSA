class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        vector<int> t(1001,0);
        vector<int> a(1001,0);
        for(int i=0;i<arr.size();i++){
            t[arr[i]]++;
            a[target[i]]++;
        }
        for(int i=0;i<1001;i++){
            if(t[i]!=a[i]) return false;
        }
        return true;
    }
};