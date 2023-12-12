class Solution {
public:
    int FindHeight(TreeNode* root,int &diameter){
        if(root==NULL){
            return 0;
        }
        int left = FindHeight(root->left,diameter);
        int right = FindHeight(root->right,diameter);
        diameter = max(diameter,left+right);
        return max(left,right)+1;
    }   
    
    int diameterOfBinaryTree(TreeNode* root) {
        int diameter = 0;
        FindHeight(root,diameter);
        return diameter;
    }
};