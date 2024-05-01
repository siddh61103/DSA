class Solution {
public:
    string reversePrefix(string word, char ch) {
        int a = 0;
        for(int i=0;i<word.size();i++){
            if(word[i]==ch) {
                a=i;
                break;
            }
        }
        reverse(word.begin(),word.begin()+a+1);
        return word;
    }
};