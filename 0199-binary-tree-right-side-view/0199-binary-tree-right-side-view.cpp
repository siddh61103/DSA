class Solution {
public:
void give_right_view(TreeNode* root, vector<int>& ans,int n){
    if(root==NULL) return;
    
    if(n == ans.size()) ans.push_back(root->val);
    give_right_view(root->right, ans, n+1);
    give_right_view(root->left, ans, n+1);
}
vector<int> rightSideView(TreeNode* root) {
    vector<int> ans;
    give_right_view(root,ans,0);
    return ans;
}
};