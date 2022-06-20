// problem link --> https://leetcode.com/problems/binary-tree-paths/

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
    void dfs(TreeNode* root,string path,vector<string> &ans)
    {
        if(root==NULL) return;
        else if(root->left==NULL && root->right==NULL){
            path+=to_string(root->val);
            ans.push_back(path);
            return;
        }
        
        path+=to_string(root->val);
        path+="->";
        if(root->left!=NULL) dfs(root->left,path,ans);
        if(root->right!=NULL) dfs(root->right,path,ans);
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        if(root==NULL) return ans;
        dfs(root,"",ans);
        return ans;
    }
};