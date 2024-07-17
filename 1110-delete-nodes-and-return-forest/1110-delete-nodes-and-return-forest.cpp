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
    int solve(TreeNode* root, vector<TreeNode*> &ans, set<int> &set, int a){
        if(root==NULL){
            return 1;
        }
        int m = 1;
        if(set.find(root->val)!=set.end()){
            m=0;
            a=1;
        }
        else if(a==1){
            ans.push_back(root);
            a=0;
        }
        int i = solve(root->left, ans, set, a);
        int j = solve(root->right, ans, set, a);
        if(i==0) root->left=NULL;
        if(j==0) root->right=NULL;
        return m;
    }
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        set<int> set;
        for(auto i : to_delete){
            set.insert(i);
        }
        vector<TreeNode*> ans;
        vector<int> v;
        solve(root,ans, set,1);
        return ans;
    }
};