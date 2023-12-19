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
    void morris_traversal(TreeNode* root,int k,int &count,int &ans){
        while(root!=NULL){
            if(root->left){
                TreeNode* temp = root->left;
                while(temp->right!=NULL && temp->right!=root){
                    temp = temp->right;
                }
                if(temp->right==NULL){
                    temp->right = root;
                    root = root->left;
                }
                else{
                    count++;
                    if(count ==k) ans = root->val;
                    root = root->right;
                    temp->right = NULL;
                }
            }
            else{
                count++;
                if(count ==k) ans = root->val;
                root = root->right;
            }
        }
    }
    int kthSmallest(TreeNode* root, int k) {
        int count = 0;
        int ans = 0;
        morris_traversal(root,k,count,ans);
        return ans;
    }
};