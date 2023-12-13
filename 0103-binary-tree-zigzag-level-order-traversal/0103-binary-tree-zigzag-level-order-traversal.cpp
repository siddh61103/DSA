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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root==NULL) return ans;
        bool flag = true;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            vector<int> level(size);
            for(int i=0; i<size; i++){
                root = q.front();
                q.pop();
                int index = flag ? i : size-i-1;
                if(root->left!=NULL) q.push(root->left);
                if(root->right!=NULL) q.push(root->right);
                level[index]=root->val;
            }
            ans.push_back(level);
            flag = !flag;
        }
        return ans;
    }
};