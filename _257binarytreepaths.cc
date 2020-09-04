/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void dfs(vector<string>& res, string tmp, TreeNode* root){
        if(root->right==NULL&&root->left==NULL){
            tmp+=to_string(root->val);
            res.push_back(tmp);
            return;
        }
        if(root->left)dfs(res, tmp+to_string(root->val)+"->", root->left);
        if(root->right)dfs(res, tmp+to_string(root->val)+"->", root->right);
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        if(root==NULL)return {};
        vector<string> res;
        dfs(res, "", root);
        return res;
    }
};
