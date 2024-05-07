class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(),people.end());
        int ans = 0;
        int i = 0;
        int j = people.size();
        while(i<j){
            j--;
            if(people[i]+people[j]<=limit) i++;
            ans++;
        }
        return ans;
    }
};