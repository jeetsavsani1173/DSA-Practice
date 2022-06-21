// problem link --> https://leetcode.com/problems/distribute-coins-in-binary-tree/

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
    int step;
    int dfs(TreeNode* root)
    {
        if(root==NULL) return 0;
        int lreq=dfs(root->left);
        int rreq=dfs(root->right);
        step+=(abs(lreq)+abs(rreq));
        return lreq+rreq+(root->val-1);
    }
    int distributeCoins(TreeNode* root) {
        dfs(root);
        return step;
    }
};