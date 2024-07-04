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
    ListNode* mergeNodes(ListNode* head) {
        ListNode* temp = head->next;

        ListNode* prev = temp;
        int c = 0;
        while(temp!=NULL){
            c+=temp->val;
            if(temp->val==0){
                prev->val = c;
                prev->next = temp->next;
                prev = temp->next;
                c=0;
            }
            temp = temp->next;
        }
        return head->next;
    }
};