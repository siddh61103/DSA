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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* i = list1;
        ListNode* j = list2;
        ListNode* ans = new ListNode(0);
        ListNode* temp = ans;
        while(i && j){
            if(i->val <= j->val){
                temp->next = i;
                temp = temp->next;
                i = i->next;
            }
            else{
                temp->next = j;
                temp = temp->next;
                j = j->next;
            }
        }
        while(i){
                temp->next = i;
                temp = temp->next;
                i = i->next;
        }
        while(j){
                temp->next = j;
                temp = temp->next;
                j = j->next;
        }
        return ans->next;
    }
};