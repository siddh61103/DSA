
class BSTIterator {
public:
    stack<TreeNode*> s;
    bool reverse = true;
    BSTIterator(TreeNode* root,bool isReverse) {
        reverse = isReverse;
        pushall(root);
        
    }
    int next() {
        TreeNode* temp = s.top();
        s.pop();
        if(!reverse) pushall(temp->right);
        else{
            pushall(temp->left);
        }
        return temp->val;
    }
    
    bool hasNext() {
        return !s.empty();
    }
    void pushall(TreeNode* root){
            while(root!=NULL){
                s.push(root);
                if(reverse){
                    root= root->right;
                }
                else{
                    root= root->left;
                }
            }
    }
};
class Solution {
public:
    bool findTarget(TreeNode* root, int k){
        if(root==NULL) return false;
        //for next element---ascending
        BSTIterator l(root,false);
        //for previous Element or before Element---descending
        BSTIterator r(root,true);
        int i = l.next();
        int j = r.next(); //r.before()
        while(i<j){
            if(i+j==k) return true;
            if(i+j > k){
                j = r.next();
            }
            else{
                i = l.next();
            }
        }
        return false;
     }
};
