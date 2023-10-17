class Solution {
    public String longestCommonPrefix(String[] strs) {
        int n = strs.length;
        int m = 0;
        String ans = "";
        char c;
        int t = 201;
        for(int i = 0;i < n ;i++){ 
            if(strs[i].length() < t){
                t = strs[i].length();
            }
        }
        while(m<t){
            c = strs[0].charAt(m);
            for(int i = 0;i < n;i++){
                if(c!=strs[i].charAt(m)){
                    return ans;
                }
            }
            m++;
            ans = ans + c;
        }
        return ans;
    }
}