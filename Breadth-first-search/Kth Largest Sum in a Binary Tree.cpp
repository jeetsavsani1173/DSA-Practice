// problem link --> https://leetcode.com/problems/kth-largest-sum-in-a-binary-tree/

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
    vector<long long> sum;
    void bfs(TreeNode *root)
    {
        queue<TreeNode *> q;
        q.push(root);

        while (!q.empty())
        {
            long long sm = 0;
            int sz = q.size();
            while (sz--)
            {
                auto it = q.front();
                q.pop();
                sm += (it->val);
                if (it->left)
                    q.push(it->left);
                if (it->right)
                    q.push(it->right);
            }
            sum.push_back(sm);
        }
    }
    long long kthLargestLevelSum(TreeNode *root, int k)
    {
        bfs(root);
        sort(sum.begin(), sum.end());
        reverse(sum.begin(), sum.end());
        if (sum.size() < k)
        {
            return -1;
        }
        else
        {
            return sum[k - 1];
        }
    }
};