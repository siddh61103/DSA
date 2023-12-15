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
    bool is_Leaf_Node(TreeNode* root){
        return (root->left == NULL && root->right == NULL);
    }
    void findPath(TreeNode* root, string s,vector<string> &ans){
        if(root==NULL) return;
        if(is_Leaf_Node(root)){
            s = s + to_string(root->val);
            ans.push_back(s);
            return ;
        }
        s = s + to_string(root->val) +"->";
        findPath(root->left,s,ans);
        findPath(root->right,s,ans);
    }
    
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string>ans;
        findPath(root,"",ans);
        return ans;
    }
};