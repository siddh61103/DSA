class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        long long int maxi = INT_MIN;
        if(root==NULL) return 0;
        queue<pair<TreeNode*,long long int>>q;
        q.push({root,0});
        while(!q.empty()){
            long long int size = q.size();
            long long int curr_minium =  q.front().second; // used  to prevent integer overflow
            long long int first=0,last=0;
            for(int i=0; i<size;i++){
                long long int curr= q.front().second - curr_minium; // it is subtracted to prevent integer overflow
                TreeNode* node = q.front().first;
                q.pop();
                if(i==0) first = curr;
                if(i==size-1) last = curr;
                if(node->left) q.push({node->left,(2*(curr))+1});
                if(node->right) q.push({node->right,(2*(curr))+2});
            }
            maxi = max(maxi,last-first+1);
        }
        return maxi;
        
    }
};