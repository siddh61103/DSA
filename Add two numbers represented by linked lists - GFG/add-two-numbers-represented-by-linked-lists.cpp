//{ Driver Code Starts
// driver

#include <bits/stdc++.h>
using namespace std;

/* Linked list Node */
struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node* buildList(int size)
{
    int val;
    cin>> val;
    
    Node* head = new Node(val);
    Node* tail = head;
    
    for(int i=0; i<size-1; i++)
    {
        cin>> val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

void printList(Node* n)
{
    while(n)
    {
        cout<< n->data << " ";
        n = n->next;
    }
    cout<< endl;
}


// } Driver Code Ends
/* node for linked list:

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/
 void insertAt(Node*&head, Node*&tail,int digit){
        Node * temp = new Node(digit);
        if(head == NULL){
            head = temp;
            tail = temp;
            return;
        }
        else{
            tail->next = temp;
            tail = temp;
        }
    }
    Node* add(Node* l1,Node* l2){
        int carry = 0;
        
        Node *ansHead = NULL;
        Node *ansTail = NULL;
        
        while(l1 != NULL || l2 != NULL || carry !=0 ){
            int v1 = 0;
            if(l1!=NULL){
                v1 = l1->data;
            }
            int v2 = 0;
            if(l2!=NULL){
                v2 = l2->data;
            }
            
            int sum = carry + v1 + v2;
            
            int digit = sum % 10;
            
            insertAt(ansHead, ansTail, digit);
            
            carry = sum/10;
            
            if(l1 != NULL){
                l1 = l1->next;
            }
            if(l2 != NULL){
                l2 = l2->next;
            }
        }
        return ansHead;
    }
    Node *reverse(Node*&head){
        Node *prev = NULL;
        Node *curr = head; 
        Node *next = NULL;
        while(curr!=NULL){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            }
        return prev;
    }

class Solution
{
    public:
    //Function to add two numbers represented by linked list.
    struct Node* addTwoLists(struct Node* first, struct Node* second)
    {
        first = reverse(first);
        second = reverse(second);
        Node *temp  = add(first,second);
        return reverse(temp);
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, m;
        
        cin>>n;
        Node* first = buildList(n);
        
        cin>>m;
        Node* second = buildList(m);
        Solution ob;
        Node* res = ob.addTwoLists(first,second);
        printList(res);
    }
    return 0;
}

// } Driver Code Ends