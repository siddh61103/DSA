/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int solve(TreeNode* root, int s,int e, int &start,string &end, string &temp){
        if(root==NULL) return 0;
        int a = -1;
        int b = -1;
        temp+="L";
        a = solve(root->left, s, e, start, end,temp);
        temp.pop_back();
        temp+="R";
        b = solve(root->right, s, e, start, end, temp);
        temp.pop_back();
        if(a==1 || b==1){
            start++;
            return 1;
        }
        if(root->val==e){
            end=temp;
            return 0;
        }
        if(root->val==s) return 1;
        return 0;
    }
    int lcs(TreeNode* root, int s, int e,TreeNode* & ancestor){
        if(root==NULL) return 0;
        int c=0;
        if(root->val==s || root->val==e) c++;
        if(lcs(root->left, s, e, ancestor)) c++;
        if(lcs(root->right, s, e, ancestor)) c++;
        if(c==2) ancestor = root;
        if(c==1) return 1;
        else return 0;
    }
    string getDirections(TreeNode* root, int startValue, int destValue) {
        TreeNode * ancestor;
        lcs(root, startValue, destValue, ancestor);
        string ans="";
        int start = 0;
        string end="";
        string temp = "";
        solve(ancestor, startValue, destValue, start, end,temp);
        while(start--){
            ans+="U";
        }
        ans+=end;
        return ans;
    }
};