// problem link --> https://practice.geeksforgeeks.org/problems/maximum-sum-of-non-adjacent-nodes/1

class Solution
{
public:
    pair<int, int> dfs(Node *root)
    {
        if (root == NULL)
            return {0, 0};

        pair<int, int> l = dfs(root->left);
        pair<int, int> r = dfs(root->right);

        pair<int, int> cAns;
        cAns.first = root->data + l.second + r.second;
        cAns.second = max(l.first, l.second) + max(r.first, r.second);

        return cAns;
    }
    int getMaxSum(Node *root)
    {
        // pair<int,int> -> <including,excluding>
        pair<int, int> ans = dfs(root);
        return max(ans.first, ans.second);
    }
};