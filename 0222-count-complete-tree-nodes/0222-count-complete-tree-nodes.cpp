class Solution {
public:
    void inorder(TreeNode* root,int &ans){
        if(root==NULL) return;
        inorder(root->left,ans);
        ans++;
        inorder(root->right,ans);
    }
    int countNodes(TreeNode* root) {
        int ans = 0;
        inorder(root,ans);
        return ans;
        
    }
};