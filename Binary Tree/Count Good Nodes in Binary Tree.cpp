// problem link--> https://leetcode.com/problems/count-good-nodes-in-binary-tree/

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
    int count;
    void dfs(TreeNode* root,int mx)
    {
        if(!root) return;
        if(root->val>=mx){
            count++;
        }
        mx=max(mx,root->val);
        dfs(root->left,mx);
        dfs(root->right,mx);
    }
    int goodNodes(TreeNode* root) {
        count=0;
        dfs(root,INT_MIN);
        return count;
    }
};