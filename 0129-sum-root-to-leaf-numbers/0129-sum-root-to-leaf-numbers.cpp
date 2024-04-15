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
    int solve(TreeNode* root, int n){
        n = n*10 + root->val;
        int a = 0;
        int b = 0;
        if(root->left!=NULL){
            a = solve(root->left,n);
        }
        if(root->right!=NULL){
            b = solve(root->right,n);
        }
        if(root->right==NULL && root->left==NULL){
            return n;
        }
        return a+b;
    }
    int sumNumbers(TreeNode* root) {
        return solve(root,0);
    }
};