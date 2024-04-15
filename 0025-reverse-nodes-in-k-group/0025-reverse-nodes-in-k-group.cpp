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
    ListNode* reverseKGroup(ListNode* head, int k) {
        vector<int> vec;
        ListNode* temp = head;
        while(temp!=NULL){
            vec.push_back(temp->val);
            temp = temp->next;
        }
        int i = 0;
        while(i+k <= vec.size()){
            reverse(vec.begin()+i, vec.begin() + i + k);
            i+=k;
        }
        i = 0;
        temp = head;
        while(temp!=NULL){
            temp->val = vec[i];
            i++;
            temp = temp->next;
        }
        return head;
    }
};