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
ListNode* merge(ListNode* &first, ListNode* &second) {
    if(first->next == NULL){
        first->next = second;
        return first;
    }
    ListNode* curr1 = first;
    ListNode* next1 = first->next;
    ListNode* curr2 = second;
    ListNode* next2 = second->next;
    while(next1!=NULL && curr2!=NULL){
        if((curr1->val)<=(curr2->val) && (curr2->val)<=(curr1->next->val)){
            //adding node
            next2 = curr2->next;
            curr2->next = curr1->next;
            curr1->next = curr2;
            //updating pointers
            curr1 = curr2;
            curr2 = next2;
        }
        else{
            curr1 = curr1->next;
            next1 = curr1->next;
            if(curr1->next==NULL){
                curr1->next = curr2;
                return first;
            }
        }
    }
    return first;
}
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1==NULL){
            return list2;
        }
        if(list2==NULL){
            return list1;
        }
        if(list1->val<=list2->val){
            return merge(list1,list2);
        }
        else{
            return merge(list2,list1);
        }
        
    }
};