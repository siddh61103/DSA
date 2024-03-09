class Solution {
public:
    int nextGreaterElement(int n) {
        vector<int>ans;
        while(n>0){
            ans.push_back(n%10);
            n = n/10;
        }
        reverse(ans.begin(),ans.end());
        int h = ans.size();
        int k = -1;
        for(int i=h-2;i>=0;i--){
            if(ans[i] < ans[i+1]){
                k = i;
                break;
            }
        }
        if(k==-1) return -1;
        for(int j = h-1;j>=k+1;j--){
            if(ans[j]>ans[k]){
                swap(ans[j],ans[k]);
                break;
            }
        }
        reverse(ans.begin()+k+1,ans.end());
        long long sum = 0;
        for(auto i : ans){
            sum = sum*10 + i;
        }
        if(sum>INT_MAX) return -1;
        return sum;
    }
};