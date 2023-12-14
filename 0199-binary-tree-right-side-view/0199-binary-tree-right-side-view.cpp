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
void give_right_view(TreeNode* root, vector<int>& ans,int n,int &count){
    if(root==NULL){
        return;
    }
    ans[n] = root->val;
    count = max(count,n+1);
    give_right_view(root->left,ans,n+1,count);
    give_right_view(root->right,ans,n+1,count);
    return;
}
    vector<int> rightSideView(TreeNode* root) {
        
    if(root==NULL) return {};
    int count = 0;
    vector<int> ans(101,-1);
    give_right_view(root,ans,0,count);
    ans.resize(count);
    return ans;
        
    }
};