class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        
        sort(citations.begin(),citations.end());
        
        for(int i = citations[n-1]; i >= 0;i--){
            int count = 0;
            for( int j = 0; j < n;j++){
                if(citations[j] >= i){
                    count++;
                }
            }
            if(count >= i ){
                return i;
            }
        }
        return 0;
    }
};