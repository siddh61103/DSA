class Solution {
public:
    int solve(TreeNode* root,int &ans){
        if(root==NULL) return 0;
        int a = solve(root->left,ans);
        int b = solve(root->right,ans);
        ans = max(ans,a+b);
        return 1 + max(a,b);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int ans = 0;
        solve(root,ans);
        return ans;
    }
};