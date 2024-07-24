// /**
//  * Definition for a binary tree node.
//  * struct TreeNode {
//  *     int val;
//  *     TreeNode *left;
//  *     TreeNode *right;
//  *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//  *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//  *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
//  * };
//  */
class Solution {
public:
    void findleaf(TreeNode* root, vector<TreeNode*> & leaf, unordered_map<TreeNode*,TreeNode*> &mp,TreeNode* parent){
        if(root==NULL) return ;
        mp[root] = parent;
        if(!root->right && !root->left) {
            leaf.push_back(root);
            return ;
        }
        findleaf(root->left,leaf,mp,root);
        findleaf(root->right,leaf,mp,root);
        return ;
    }
    void solve (TreeNode* root, int d,int &ans, unordered_map<TreeNode*,TreeNode*> &mp){
        if(root==NULL) return ;
        TreeNode* temp = mp[root];
        if(d<0) return ;
        mp.erase(root);
        d-=1;
        //going to left
        if(mp.find(root->right)!=mp.end()) solve(root->right, d, ans, mp);
        //going to right
        if(mp.find(root->left)!=mp.end()) solve(root->left, d, ans, mp);
        //going to parent
        if(mp.find(temp)!=mp.end()) solve(temp, d, ans, mp);
        //adding for leaf
        if(!root->right && !root->left) ans++;
        return ;
    }
    int countPairs(TreeNode* root, int distance) {
        unordered_map<TreeNode*,TreeNode*> mp;
        vector<TreeNode*> leaf;
        findleaf(root, leaf,mp,NULL);
        int sum = 0;
        int ans = 0;
        for(auto i : leaf){
            unordered_map<TreeNode*,TreeNode*> mpt;
            mpt = mp;
            solve(i,distance,ans,mpt);
            //minus 1 in ans because current leaf node is adding 1 in recursion
            ans-=1;
        }
        return ans/2;
    }

};