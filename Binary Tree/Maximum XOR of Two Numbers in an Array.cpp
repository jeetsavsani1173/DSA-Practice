// problem link --> https://leetcode.com/problems/maximum-xor-of-two-numbers-in-an-array/description/

class Solution
{
public:
    // Trie Node.
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

        int ans = 0;
        for (int i = 31; i >= 0; i--)
        {
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
    int findMaximumXOR(vector<int> &nums)
    {
        for (auto it : nums)
        {
            insert(it);
        }

        int ans = 0;

        for (auto it : nums)
            ans = max(ans, it ^ search(~it));

        return ans;
    }
};