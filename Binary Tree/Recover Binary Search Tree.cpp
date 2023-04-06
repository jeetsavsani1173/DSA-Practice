// problem link --> https://leetcode.com/problems/recover-binary-search-tree/

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
class Solution
{
public:
    TreeNode *start = NULL;
    TreeNode *mid = NULL;
    TreeNode *end = NULL;
    TreeNode *prev = NULL;
    void dfs(TreeNode *root)
    {
        if (root == NULL)
            return;
        dfs(root->left);
        // do all work here
        if (prev)
        {
            if (prev->val > root->val)
            { // found wrong node.
                if (start)
                {
                    end = root;
                }
                else
                {
                    start = prev;
                    mid = root;
                }
            }
        }
        prev = root;
        dfs(root->right);
    }
    void recoverTree(TreeNode *root)
    {
        dfs(root);
        if (end == NULL)
        {
            swap(start->val, mid->val);
        }
        else
        {
            // cout<<"ffdd"<<endl;
            swap(start->val, end->val);
        }
    }
};