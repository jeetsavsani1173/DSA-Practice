// problem link --> https://practice.geeksforgeeks.org/problems/construct-tree-1/1

class Solution
{
public:
    int find_index(int a[], int s, int e, int t)
    {
        for (int i = s; i <= e; i++)
        {
            if (a[i] == t)
                return i;
        }
    }
    Node *buildTree(int in[], int pre[], int n, int s1, int e1, int s2, int e2)
    {
        if (s1 > e1 || s2 > e2)
        {
            return NULL;
        }
        int index = find_index(in, s1, e1, pre[s2]);
        Node *curr = new Node(pre[s2]);
        int mid = s2 + (index - s1);
        curr->left = buildTree(in, pre, n, s1, index - 1, s2 + 1, mid);
        curr->right = buildTree(in, pre, n, index + 1, e1, mid + 1, e2);
        return curr;
    }
    Node *buildTree(int in[], int pre[], int n)
    {
        return buildTree(in, pre, n, 0, n - 1, 0, n - 1);
    }
};