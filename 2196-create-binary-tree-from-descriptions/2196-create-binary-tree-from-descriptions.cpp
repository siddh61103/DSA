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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int,TreeNode*> mp;
        unordered_map<int,int> findroot;
        for(auto i: descriptions){
            if(findroot.find(i[0])==findroot.end()) findroot[i[0]]=0;
            TreeNode* a = NULL;
            TreeNode* b = NULL;
            if(mp.find(i[0])==mp.end()){
                a = new TreeNode(i[0]);
                mp[i[0]]=a;
            }
            else a = mp[i[0]];
            if(mp.find(i[1])==mp.end()){
                b = new TreeNode(i[1]);
                mp[i[1]]=b;
            }
            else b = mp[i[1]];
            
            if(i[2]==1) a->left = b;
            else a->right = b;
            
            findroot[i[1]]=1;
        }
        for(auto i : findroot){
            if(i.second==0) return mp[i.first];
        }
        return NULL;
    }
};