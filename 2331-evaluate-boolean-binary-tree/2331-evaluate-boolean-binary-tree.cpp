/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int solve(TreeNode* root){
        if(root->val==2) return solve(root->left) || solve(root->right);
        else if(root->val==3) return solve(root->left) && solve(root->right);
        return root->val;
    }
    bool evaluateTree(TreeNode* root) {
        return solve(root);
    }
};