class Solution {
public:
    int FindHeight(TreeNode* root){
        if(root==NULL){
            return 0;
        }
        int left = FindHeight(root->left);
        int right = FindHeight(root->right);
        return max(left,right)+1;
    }
    int check(TreeNode* root,int maxi){
        if(root==NULL) return 0 ;
        int x=check(root->left,maxi);
        int y=check(root->right,maxi);
        int lh = FindHeight(root->left);
        int rh = FindHeight(root->right);
        int temp = lh+rh;
        
        return max(temp,max(x,y));
    }
    
    
    
    int diameterOfBinaryTree(TreeNode* root) {
       return check(root,0);
    }
};