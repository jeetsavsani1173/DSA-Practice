// problem link --> https://practice.geeksforgeeks.org/problems/zigzag-tree-traversal/0

class Solution
{
public:
    // Function to store the zig zag order traversal of tree in a list.
    vector<int> zigZagTraversal(Node *root)
    {
        vector<int> ans;
        if (root == NULL)
            return ans;
        queue<Node *> q;
        q.push(root);
        bool leftToRight = true;
        while (!q.empty())
        {
            int sz = q.size();
            vector<int> temp_ans(sz);
            for (int i = 0; i < sz; i++)
            { // for differentiate each level..
                auto it = q.front();
                q.pop();
                int index = (leftToRight) ? (i) : (sz - i - 1);
                temp_ans[index] = (it->data);

                if (it->left)
                    q.push(it->left);
                if (it->right)
                    q.push(it->right);
            }
            leftToRight = !leftToRight;
            for (auto i : temp_ans)
                ans.push_back(i);
        }
        return ans;
    }
};