class Solution {
public:
    bool haveConflict(vector<string>& event1, vector<string>& event2) {
        for(int i = 0;i < 2;i++){
            string str = event1[i];
            str.erase(str.begin() + 2);
            event1[i] = str;
            str = event2[i];
            str.erase(str.begin() + 2);
            event2[i] = str;
        }
        int st1 = stoi (event1[0]);
        int et1 = stoi (event1[1]);
        int st2 = stoi (event2[0]);
        int et2 = stoi (event2[1]);
        if(st2>=st1 && st2<=et1 || st1>=st2 && st1<=et2){
            return true;
        }
        else{
            return false;
        }
    }
};