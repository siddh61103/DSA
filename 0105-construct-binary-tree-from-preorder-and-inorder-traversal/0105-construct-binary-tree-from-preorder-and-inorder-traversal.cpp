class Solution {
public:
    TreeNode*buildingTree(vector<int> &preorder, vector<int> &inorder,map<int,int> &mp,int preSt,int preEd,int inSt,int inEd){
        
        if(preSt > preEd || inSt > inEd) return NULL;
        
        TreeNode* node= new TreeNode(preorder[preSt]);
        
        int curr_root = mp[node->val];
        int left = curr_root - inSt;
                                     
        node->left = buildingTree( preorder, inorder, mp, preSt+1, preSt+left , inSt, curr_root-1);
                                     
        node->right = buildingTree(preorder, inorder, mp, preSt+left+1, preEd, curr_root+1,  inEd);
                                     
        return node;
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        map<int ,int> mp;
        for(int i = 0; i < inorder.size();i++){
            mp[inorder[i]] = i;
        }
        
        TreeNode* root = buildingTree(preorder, inorder, mp, 0, preorder.size()-1, 0, inorder.size()-1);
        return root;
    }
};