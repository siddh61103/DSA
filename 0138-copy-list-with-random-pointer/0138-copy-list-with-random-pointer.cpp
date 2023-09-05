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
void insertAt(Node* &head, Node* &tail, int value){
    Node* temp = new Node(value);
    if(head == NULL){
        head = temp;
        tail = temp;
    }
    else{
        tail->next = temp;
        tail = temp;
    }
    return;
}
class Solution {
public:
    Node* copyRandomList(Node* head) {
        // 1. create a clone node
        Node * clonehead = NULL;
        Node* clonetail = NULL;
        
        Node* temp = head;
        while(temp!=NULL){
            insertAt(clonehead,clonetail,temp->val);
            temp = temp->next;
        }
        // 2. add clone node between original list
        Node *originalnode = head;
        Node *clonenode = clonehead;
        
        while(originalnode!=NULL && clonenode!=NULL){
            Node*temp = originalnode->next;
            originalnode->next = clonenode;
            originalnode = temp;
            
            temp = clonenode->next;
            clonenode->next = originalnode;
            clonenode = temp;
            
        }
        // 3. copy random pointer 
        temp = head;
        while(temp != NULL){
            if(temp->next != NULL){
                temp->next->random = temp->random? temp->random->next: temp->random;
                temp = temp->next->next;
            }
        }
        
        // 4.revert changes of step2
        originalnode = head;
        clonenode = clonehead;
        
        while(originalnode!=NULL && clonenode!=NULL){
            
            originalnode->next = clonenode->next;
            originalnode = originalnode->next;
            if(originalnode!=NULL){
                clonenode->next = originalnode->next;
            }
            clonenode = clonenode->next;
        }
        // 5.return answer
        return clonehead;
        
    }
};




























