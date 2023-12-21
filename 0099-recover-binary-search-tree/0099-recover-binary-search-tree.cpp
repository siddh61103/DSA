class Solution {
public:
    TreeNode* first;
    TreeNode* prev;
    TreeNode* middle;
    TreeNode* last;
    void inorder(TreeNode* root){
        if(root==NULL) return ;
        inorder(root->left);
        
        if(prev->val>root->val){
            if(first==NULL){
                first = prev;
                middle = root;
            }
            else{
                last = root;
            }
        }
        prev = root;
            
        inorder(root->right);
        
    }
    
    void recoverTree(TreeNode* root) {
        first = middle = last =NULL;
        prev = new TreeNode  (INT_MIN);
        inorder(root);
        if(last){
            swap(first->val, last->val);
        }
        else if (middle){
            swap(first->val,middle->val);
        }
    }
};