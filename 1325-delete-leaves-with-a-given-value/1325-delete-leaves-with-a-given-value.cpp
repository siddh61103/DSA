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
    int solve(TreeNode* root, int t){
        if(root->right) if(solve(root->right, t)) root->right = NULL;
        if(root->left) if(solve(root->left, t)) root->left = NULL;
        if(root->val==t){
            if(!root->right && !root->left){
                return 1;
            }
        }
        return 0;
    }
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        if(solve(root, target)) return NULL;
        return root;
    }
};