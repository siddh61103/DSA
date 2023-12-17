/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root==NULL) return "";
        string s = "";
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            TreeNode* root = q.front();
            q.pop();
            if(root==NULL) s.append("#,");
            else s.append(to_string(root->val)+",");
            if(!(root==NULL)){
                q.push(root->left);
                q.push(root->right);
            }
        }
        cout<<s<<" ";
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) { 
        if(data.size()==0) return NULL;
        TreeNode* n = new TreeNode(3);
        stringstream s(data);
        string str;
        getline(s,str,',');
        TreeNode* root = new TreeNode(stoi(str));
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            
            TreeNode* root = q.front();
            q.pop();
            
            getline(s,str,',');
            
            if(str == "#"){
                root->left = NULL;
            }
            else{
                TreeNode* node = new TreeNode(stoi(str));
                root->left = node;
                q.push(root->left);
            }
            
            getline(s,str,',');
            if(str=="#"){
                root->right = NULL;
            }
            else{
                TreeNode* node = new TreeNode(stoi(str));
                root->right = node;
                q.push(root->right);
            }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));