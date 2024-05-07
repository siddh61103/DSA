class Solution {
public:
    int compareVersion(string version1, string version2) {
        int i = 0;
        int j = 0;
        int n = 0;
        while(n==0){
            n=1;
            string s1 = "";
            string s2 = "";
            int a = 0;
            int b = 0;
            while(i< version1.size() && version1[i]!='.'){
                n=0;
                s1+=version1[i];
                i++;
                a = stoi(s1);
            }
            i++;
            while(j< version2.size() && version2[j]!='.'){
                n=0;
                s2+=version2[j];
                j++;
                b = stoi(s2);
            }
            j++;
            if(b==a) continue;
            else if(b>a) return -1;
            else return 1;
        }
        return 0;
    }
};