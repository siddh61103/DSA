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
    int FindHeight(TreeNode* root){
        if(root==NULL){
            return 0 ;
        }
        int left = FindHeight(root->left);
        int right = FindHeight(root->right);
        return max(left,right)+1;
    }
    bool isBalanced(TreeNode* root) {
        if(root==NULL){
            return true ;
        }
        int lh = FindHeight(root->left);
        int rh = FindHeight(root->right);
        if( abs(lh - rh) >1 ){
            return false;
        }
        bool left = isBalanced(root->left);
        bool right = isBalanced(root->right);
        if(left && right){
            return true;
        }
        return false;
    }
};