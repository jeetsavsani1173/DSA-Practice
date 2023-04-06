// problem link --> https://leetcode.com/problems/two-sum-iv-input-is-a-bst/

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
    stack<TreeNode *> st1, st2;
    void init(TreeNode *root)
    {
        TreeNode *l = root;
        while (l)
        {
            st1.push(l);
            l = l->left;
        }
        TreeNode *r = root;
        while (r)
        {
            st2.push(r);
            r = r->right;
        }
    }
    int next()
    {
        TreeNode *st = st1.top();
        st1.pop();

        if (st->right)
        {
            TreeNode *curr = st->right;
            while (curr)
            {
                st1.push(curr);
                curr = curr->left;
            }
        }
        return st->val;
    }

    int prev()
    {
        TreeNode *st = st2.top();
        st2.pop();

        if (st->left)
        {
            TreeNode *curr = st->left;
            while (curr)
            {
                st2.push(curr);
                curr = curr->right;
            }
        }
        return st->val;
    }
    bool findTarget(TreeNode *root, int k)
    {
        init(root);
        int i = next(), j = prev();
        while (i < j)
        {
            if ((i + j) == k)
                return true;
            if ((i + j) < k)
            {
                i = next();
            }
            else
            {
                j = prev();
            }
        }
        return false;
    }
};