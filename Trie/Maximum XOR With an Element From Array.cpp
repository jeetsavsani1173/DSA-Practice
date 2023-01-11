// problem link --> https://leetcode.com/problems/maximum-xor-with-an-element-from-array/description/

class Solution
{
public:
    struct Node
    {
        Node *left;
        Node *right;
    };

    void insert(int val)
    {
        Node *curr = root;

        for (int i = 31; i >= 0; i--)
        {
            if (val & (1 << i))
            {
                // set bit
                if (curr->right == NULL)
                {
                    Node *temp = new Node();
                    curr->right = temp;
                }
                curr = curr->right;
            }
            else
            {
                // bit is unset
                if (curr->left == NULL)
                {
                    Node *temp = new Node();
                    curr->left = temp;
                }
                curr = curr->left;
            }
        }
    }

    int search(int val)
    {
        Node *curr = root;

        if (curr == NULL)
            return -1;

        int ans = 0;
        for (int i = 31; i >= 0; i--)
        {
            if (curr == NULL)
                return -1;
            if (val & (1 << i))
            {
                // set
                if (curr->right != NULL)
                {
                    curr = curr->right;
                    ans = ans | (1 << i);
                }
                else
                {
                    curr = curr->left;
                }
            }
            else
            {
                // unset
                if (curr->left != NULL)
                {
                    curr = curr->left;
                }
                else
                {
                    curr = curr->right;
                    ans = ans | (1 << i);
                }
            }
        }
        return ans;
    }
    Node *root = new Node();
    vector<int> maximizeXor(vector<int> &nums, vector<vector<int>> &queries)
    {
        vector<int> ans(queries.size(), 0);
        vector<vector<int>> q;
        for (int i = 0; i < queries.size(); i++)
        {
            q.push_back({queries[i][1], queries[i][0], i});
        }
        sort(q.begin(), q.end());
        sort(nums.begin(), nums.end());
        int idx = 0;
        for (int i = 0; i < q.size(); i++)
        {
            int limit = q[i][0];
            while (idx < nums.size() && nums[idx] <= limit)
            {
                insert(nums[idx]);
                idx++;
            }
            int rans = search(~q[i][1]);
            if (rans != -1)
                ans[q[i][2]] = q[i][1] ^ rans;
            else
                ans[q[i][2]] = rans;
        }
        return ans;
    }
};