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
void dfs(int node,vector<vector<int>> &vec, vector<int>&vis,int &ans,int t){
    vis[node]=1;
    if(t>ans) ans = t;
    for(auto i : vec[node]){
        if(vis[i]==0){
            dfs(i,vec,vis,ans,t+1);
        }
    }
    return;
}
class Solution {
public:
    int amountOfTime(TreeNode* root, int start) {
        vector<vector<int>> vec(100001);
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* temp = q.front();
            q.pop();
            int a = temp->val;
            if(temp->left){
                int b = temp->left->val;
                vec[a].push_back(b);
                vec[b].push_back(a);
                q.push(temp->left);
            }
            if(temp->right){
                int b = temp->right->val;
                vec[a].push_back(b);
                vec[b].push_back(a);
                q.push(temp->right);
            }
        }
        int ans = 0;
        vector<int> vis(100001,0);
        dfs(start,vec,vis,ans,0);
        return ans;
    }
};