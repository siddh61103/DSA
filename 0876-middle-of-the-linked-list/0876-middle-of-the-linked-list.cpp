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
ListNode* get_mid(ListNode* head){
     ListNode* fast = head->next;
     ListNode* slow = head;
    if(head == NULL || head->next== NULL){
        return head;
    }
     while(fast!= NULL){
         slow = slow->next;
         fast = fast ->next;
         if(fast!=NULL){
             fast = fast->next;
         }
     }
     return slow;
 }
 int get_length(ListNode* head){
     int len=0;
     while(head!=NULL){
         len++;
         head = head->next;
     }
     return len;
 }
class Solution {
public:
    
    ListNode* middleNode(ListNode* head) {
        return (get_mid(head));
        // int ans = get_length(head)/2;
        // ListNode* temp = head;
        // int cnt =0;
        // while(cnt<ans){
        //     temp = temp->next;
        //     cnt++;
        // }
        // return temp;
    }
};