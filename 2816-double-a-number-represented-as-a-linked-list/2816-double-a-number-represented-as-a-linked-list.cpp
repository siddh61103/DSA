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
    ListNode* solve(ListNode* head, int& n){
        int k = head->val * 2;
        ListNode *temp = new ListNode(k%10);
        if(head->next==NULL) temp->next=NULL;
        else{
            temp->next = solve(head->next,n);
            k+=n;
            temp->val = k%10;
        }
        n = k/10;
        return temp;
    }
public:
    ListNode* doubleIt(ListNode* head) {
        int a = 0;
        ListNode* ans = solve(head,a);
        if(a==0) return ans;
        ListNode* carry  = new ListNode(a);
        carry->next = ans;
        return carry;
    }
};