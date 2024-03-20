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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode*temp = list2;
        ListNode*last = list2;
        while(temp!=NULL){
            last = temp;
            temp = temp->next;
        }
        temp = list1;
        int h = 0;
        ListNode*prev = temp;
        while(temp!=NULL){
            if(h==a){
                prev->next = list2;
            }
            prev = temp;
            temp = temp->next;
            if(h==b){
                last->next = temp;
                break;
            }
            h++;
        }
        return list1;
    }
};