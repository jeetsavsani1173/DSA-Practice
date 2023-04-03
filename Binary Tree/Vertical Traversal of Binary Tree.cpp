// problem link --> https://practice.geeksforgeeks.org/problems/print-a-binary-tree-in-vertical-order/0

class Solution
{
public:
    map<int, map<int, vector<int>>> mp;
    void dfs(Node *root, int x, int y)
    {
        if (root == NULL)
            return;
        mp[y][x].push_back(root->data);

        dfs(root->left, x + 1, y - 1);
        dfs(root->right, x + 1, y + 1);
    }
    vector<int> verticalOrder(Node *root)
    {
        vector<int> ans;
        dfs(root, 0, 0);

        for (auto it : mp)
        {
            for (auto tp : it.second)
            {
                for (auto ele : tp.second)
                {
                    ans.push_back(ele);
                }
            }
        }
        return ans;
    }
};