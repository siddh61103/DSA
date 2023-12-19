class Solution {
public:
    TreeNode* find (TreeNode* root, TreeNode* p, TreeNode* q ){
        if(root==NULL || root == p || root ==q) return root;
        TreeNode* l = find(root->left,p,q);
        TreeNode* r = find(root->right,p,q);
        if(l==NULL){
            return r;
        }
        else if(r==NULL){
            return l;
        }
        return root;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return find(root, p, q);
    }
};