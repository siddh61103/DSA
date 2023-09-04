/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/
void insertAt(Node * &head,Node * &tail,int val){
    Node* temp = new Node(val);
    if(head==NULL){
        head = temp;
        tail = temp;
        return;
    }
    else{
        tail->next = temp;
        tail = temp;
    }    
}
class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node * clonehead = NULL;
        Node * clonetail = NULL;
        Node * temp = head;
        while(temp!=NULL){
            insertAt(clonehead,clonetail,temp->val);
            temp = temp->next;
        }
        //mapping
        unordered_map<Node*,Node*> originalToClone;
        Node * orignode = head;
        Node * clonenode = clonehead;
        while(orignode!=NULL && clonenode!=NULL){
            originalToClone[orignode] = clonenode; 
            orignode=orignode->next;
            clonenode=clonenode->next;
        }
        orignode=head;
        clonenode=clonehead;
        while(orignode!=NULL){
            clonenode->random = originalToClone[orignode->random];
            orignode=orignode->next;
            clonenode=clonenode->next;
        }
        return clonehead;
    }
};