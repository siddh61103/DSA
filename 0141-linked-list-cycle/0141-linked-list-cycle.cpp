/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
bool floydcycle(ListNode *head){      
        ListNode* slow =head;
        ListNode* fast = head;
        while(fast != NULL && slow!=NULL &&fast->next!=NULL){
            if(head==NULL){
                return false;
            }
            slow = slow->next;
            fast = fast->next;
            if(fast!=NULL){
                fast = fast->next;
            }
            if(slow==fast){
                // cout<< (slow->val)<<" ";
                return true;
            }
        }
        return false;
}
class Solution {
public:
    
    bool hasCycle(ListNode *head) {  
        return floydcycle(head);
    }
};