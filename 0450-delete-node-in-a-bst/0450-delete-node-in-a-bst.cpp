class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==NULL) return NULL;
        
        if(root->val==key) return helper_node(root);
        
        TreeNode* node = root;
        while(node!=NULL){
            if(node->val > key){
                if(node->left!=NULL && node->left->val==key){
                    node->left = helper_node(node->left);
                    break;
                }
                else{
                    node = node->left;
                }
            }
            else{
                if(node->right!=NULL && node->right->val==key){
                    node->right = helper_node(node->right);
                    break;
                }
                else{
                    node = node->right;
                }
            }
        }
        return root;
    }
    TreeNode* helper_node(TreeNode* node){
        if(node->left==NULL){
            return node->right;
        }
        else if(node->right==NULL){
            return node->left;
        }
        TreeNode* right = node->right;
        TreeNode* lastright = findLastRight(node->left);
        lastright->right = right;
        return node->left;
    }
    TreeNode* findLastRight(TreeNode* node){
        while(node->right){
            node = node->right;
        }
        return node;
    }
};