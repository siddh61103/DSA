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
    int findBottomLeftValue(TreeNode* root) {
        queue<pair<TreeNode*,int>> q;
        map<int,int> mp;
        q.push({root,0});
        int ans = 0;
        vector<int> vec(100000,0);
        while(!q.empty()){
            TreeNode * n = q.front().first;
            int ind = q.front().second;
            if(vec[ind]==0){
                ans = n->val;
                vec[ind]=1;
            }
            q.pop();
            if(n->left) q.push({n->left, ind+1});
            if(n->right) q.push({n->right, ind+1});
        }
        return ans;
    }
};