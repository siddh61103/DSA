class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        int n = arr.size();
        map<double,pair<int,int>> mp;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                double k = double(arr[i])/arr[j];
                mp[k] = {arr[i],arr[j]};
            }
        }
        for(auto i : mp){
            k--;
            if(k==0) return {i.second.first,i.second.second};
        }
        return {arr[0],arr[1]};
    }
};