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
//Second method
ListNode* reverse2(ListNode* &head){

     if(head == NULL || head->next == NULL){
         return head;
     }
     ListNode* smallhead = reverse2(head->next);
     head->next->next = head;
     head->next = NULL;
     return smallhead;
}
 void reverse(ListNode* &head,ListNode* &prev,ListNode* &curr){

     if(curr==NULL){
         head = prev;
         return;
     }
     reverse(head,curr,curr->next);
     curr->next= prev;
     return ;
}
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* forward = NULL;
        // reverse(head,prev,curr);
        return reverse2(head);
    }
};