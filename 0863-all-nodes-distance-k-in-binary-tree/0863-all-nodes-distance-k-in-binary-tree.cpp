class Solution {
public:
    void parentPointers(TreeNode* root, unordered_map<TreeNode*,TreeNode*> & pp){
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* root = q.front();
            q.pop();
            if(root->left){
                pp[root->left] = root;
                q.push(root->left);
            }
            if(root->right){
                pp[root->right] = root;
                q.push(root->right);
            }
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*,TreeNode*>pp; //parent pointer
        parentPointers(root,pp);
        
        unordered_map<TreeNode*,bool> visited;
        queue<TreeNode*> q;
        q.push(target);
        visited[target]=true;
        int curr_size = 0;
        while(!q.empty()){
            int size = q.size();
            if(curr_size++==k) break;
            
            for(int i=0;i<size;i++){
                TreeNode* node = q.front();
                q.pop();
                if(node->left && !visited[node->left]){
                    q.push(node->left);
                    visited[node->left] = true;
                }
                if(node->right && !visited[node->right]){
                    q.push(node->right);
                    visited[node->right] = true;
                }
                if(pp[node] && !visited[pp[node]]){
                    q.push(pp[node]);
                    visited[pp[node]] = true;
                }
            }
        }
        vector<int> ans;
        while(!q.empty()){
            ans.push_back(q.front()->val);
            q.pop();
        }
        return ans;
    }
};



        // for(auto i :pp){
        //         cout<<i.first->val<<" "<<i.second->val<<endl;
        // }