/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        map<ListNode*,bool> visited;
        
        ListNode* temp =head;
        
        while(temp!=NULL){
            // if(head==NULL){
            //     return false;
            // }
            if(visited[temp]==true){
                return true;
            }
            visited[temp]=true;
            temp = temp->next;
        }
        return false;
    }
};