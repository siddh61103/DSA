class Solution {
public:
    bool isEvenOddTree(TreeNode* root) {
        queue<pair<TreeNode*,int>>q;
        q.push({root,1});
        map<int,int> mp;
        while(!q.empty()){
            TreeNode* node = q.front().first;
            int ind = q.front().second;
            q.pop();
            if(ind % 2 ==0){
                if(node->val % 2 != 0) return false;
                if(mp.find(ind)==mp.end()){
                    mp[ind] = node->val;
                }
                else{
                    if(mp[ind] <= node->val) return false;
                    else mp[ind] = node->val;
                }
            }
            else{
                if(node->val % 2 == 0) return false;
                if(mp.find(ind)==mp.end()){
                    mp[ind] = node->val;
                }
                else{
                    if(mp[ind] >= node->val) return false;
                    else mp[ind] = node->val;
                }
            }
            if(node->left) q.push({node->left, ind+1});
            if(node->right) q.push({node->right, ind+1});
        }
        return true;
    }
};