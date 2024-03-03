class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {

        ListNode * temp = new ListNode(0);
        temp ->next = head;
        ListNode * a = temp;
        ListNode * b = temp;

        for(int i=0;i<=n;i++){
            a = a->next;
        }
        if(a == NULL) {
            head = head->next;
            return head;
        }
        
        while(a!=nullptr){
            a = a->next;
            b = b->next;
        }
        ListNode * k = b->next;
        b->next = b->next->next;
        delete k;

        return head;
    }
};