class Solution {
    public int firstUniqChar(String s) {
        int m = 0;
        int []arr = new int[26];
        for(int i = 0 ;i < s.length() ;i++){
            arr[s.charAt(i)-97]++;
        }
        for(int i = 0 ;i < s.length() ;i++){
            if(arr[s.charAt(i)-97]==1){
                return i;
            }
        }
        return -1;
    }
}