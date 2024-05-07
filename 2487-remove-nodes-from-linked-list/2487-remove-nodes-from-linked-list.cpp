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
    ListNode* removeNodes(ListNode* head) {
        ListNode* temp = head;
        stack <ListNode*> s;
        while(temp!=NULL){
            s.push(temp);
            temp = temp->next;
        }
        temp = s.top();
        s.pop();
        int n = temp->val;
        while(!s.empty()){
            ListNode* a = s.top();
            s.pop();
            if(n<=a->val){
                a->next = temp;
                temp = a;
                n = a->val;
            }
        }
        return temp;
    }
};