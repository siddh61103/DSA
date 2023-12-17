class Solution {
public:
    
    int left_height(TreeNode* root){
        int h =0;
        while(root){
            root = root->left;
            h++;
        }
        return h;
    }
    int right_height(TreeNode* root){
        int h =0;
        while(root){
            root = root->right;
            h++;
        }
        return h;
    }
    int countNodes(TreeNode* root) {
        if(root==NULL) return 0 ;
        
        int lh = left_height(root);
        
        int rh = right_height(root);
        
        if(lh==rh) return (1<<lh)-1;
        return 1 + countNodes(root->left) + countNodes(root->right); 
    }
};