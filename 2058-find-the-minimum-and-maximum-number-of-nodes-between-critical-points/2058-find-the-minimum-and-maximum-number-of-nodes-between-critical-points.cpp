/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> vec;
        ListNode* temp = head;
        int prev = -1;
        int i = 0;
        while(temp!=NULL){
            if(i==0){
                prev = temp->val;
            }
            else if(temp->next==NULL){
                break;
            }
            else{
                int a = temp->val;
                if( ( a>prev &&  a > temp->next->val ) || (a<prev &&  a < temp->next->val )){
                    vec.push_back(i);
                }
                prev = a;
            }
            i++;
            temp=temp->next;
        }
        int mini = 1e9;
        if(i<3 || vec.size()<2) return {-1,-1};
        for(int i=0;i<vec.size()-1;i++) {
            mini = min(vec[i+1]-vec[i],mini);
        }
        return {mini, vec[vec.size()-1]-vec[0]};
    }
};