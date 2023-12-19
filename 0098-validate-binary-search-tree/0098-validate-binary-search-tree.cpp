class Solution {
public:
    bool check(TreeNode* root,long int min,long int max){
        if(root==NULL) return true;
        if(root->val >=max || root->val<=min) return false;
        return check(root->left,min,root->val) &&  check(root->right,root->val,max);
    }
    
    bool isValidBST(TreeNode* root) {
        long int min = LONG_MIN;
        long int max = LONG_MAX;
        return check(root, min, max);
    }
};