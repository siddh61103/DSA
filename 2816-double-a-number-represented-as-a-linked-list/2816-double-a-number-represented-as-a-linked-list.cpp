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
        head->val = k%10;
        if(head->next==NULL) head->next=NULL;
        else{
            head->next = solve(head->next,n);
            k+=n;
            head->val = k%10;
        }
        n = k/10;
        return head;
    }
public:
    ListNode* doubleIt(ListNode* head) {
        int a = 0;
        head = solve(head,a);
        if(a==0) return head;
        ListNode* ans = new ListNode(a);
        ans->next = head;
        return ans;
    }
};