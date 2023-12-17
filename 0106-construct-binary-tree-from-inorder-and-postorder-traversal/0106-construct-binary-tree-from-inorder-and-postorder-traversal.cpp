class Solution {
public:
    TreeNode* building(vector<int>& inorder,int istart,int iend,vector<int>& postorder,int pstart,int pend,map<int,int> &mp){
         
        if(istart > iend || pstart>pend ) return  NULL;
        
        TreeNode*node = new TreeNode(postorder[pend]);
        int curr_ele = mp[node->val];
        int num_left = curr_ele-istart;
        
        node->left = building(inorder, istart, curr_ele-1, postorder, pstart, pstart + num_left -1, mp);
        node->right = building(inorder, curr_ele+1, iend , postorder , pstart+num_left,pend-1,mp);

        return node;
    }
    
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        map<int,int>mp;
        for(int i=0;i< inorder.size();i++){
            mp[inorder[i]] = i;
        }
        
        TreeNode* ans = building(inorder, 0, inorder.size()-1, postorder, 0, postorder.size()-1,mp);
        return ans;
    }
};