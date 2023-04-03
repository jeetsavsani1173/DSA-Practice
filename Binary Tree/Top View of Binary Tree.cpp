// problem link --> https://practice.geeksforgeeks.org/problems/top-view-of-binary-tree/1

class Solution
{
public:
    // Function to return a list of nodes visible from the top view
    // from left to right in Binary Tree.
    vector<int> topView(Node *root)
    {
        vector<int> ans;
        if (root == NULL)
            return ans;
        map<int, int> mp;

        queue<pair<Node *, int>> q;
        q.push({root, 0});

        while (!q.empty())
        {
            auto it = q.front();
            q.pop();

            if (mp[it.second] == 0)
            {
                mp[it.second] = it.first->data;
            }

            if (it.first->left)
                q.push({it.first->left, it.second - 1});
            if (it.first->right)
                q.push({it.first->right, it.second + 1});
        }

        for (auto it : mp)
        {
            if (it.second != 0)
            {
                ans.push_back(it.second);
            }
        }
        return ans;
    }
};