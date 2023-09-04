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
private:
    ListNode *reverse(ListNode*&head){
        ListNode *prev = NULL;
        ListNode *curr = head; 
        ListNode *next = NULL;
        while(curr!=NULL){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
    ListNode *find_mid(ListNode* head){
        ListNode *slow = head;
        ListNode *fast = head->next;
        while(fast!=NULL &&fast->next!=NULL){
            slow = slow->next;
            fast = fast->next;
            if(fast->next!= NULL){
                fast = fast->next;
            }
        }
        return slow;
    }
public:
    bool isPalindrome(ListNode* head) {
        vector<int>arr;
        ListNode *mid = find_mid(head);
        ListNode *temp = mid->next;
        temp = reverse(temp);
        ListNode * node1 = head;
        ListNode* node2 = temp;
        while(node2!=NULL){
            if(node1->val!=node2->val){
                return 0;
            }
            node2 = node2->next;
            node1 = node1->next;
        }
        temp = mid->next;
        temp = reverse(temp);
        return 1;
    }
};