// problem link --> https://practice.geeksforgeeks.org/problems/lowest-common-ancestor-in-a-binary-tree/1

// first solution
class Solution
{
public:
    Node *dfs(Node *root, int n1, int n2)
    {
        if (root == NULL)
            return NULL;
        if (root->data == n1)
            return root;
        if (root->data == n2)
            return root;

        Node *l = dfs(root->left, n1, n2);
        Node *r = dfs(root->right, n1, n2);

        if (l != NULL && r != NULL)
            return root;
        if (l != NULL)
            return l;
        else
            return r;
    }
    Node *lca(Node *root, int n1, int n2)
    {
        return dfs(root, n1, n2);
    }
};

// second solution
class Solution
{
public:
    void dfs(Node *root, int n1, vector<Node *> &path, bool &flag)
    {
        if (root == NULL)
            return;
        path.push_back(root);
        if (flag)
            return;

        if (root->data == n1)
            flag = true;

        if (root->left && !flag)
            dfs(root->left, n1, path, flag);
        if (root->right && !flag)
            dfs(root->right, n1, path, flag);

        if (!flag)
            path.pop_back();
        else
            return;
    }
    Node *lca(Node *root, int n1, int n2)
    {
        bool flag = false;
        vector<Node *> path1;
        dfs(root, n1, path1, flag);

        flag = false;
        vector<Node *> path2;
        dfs(root, n2, path2, flag);

        for (int i = min(path1.size(), path2.size()) - 1; i >= 0; i--)
        {
            if (path1[i] == path2[i])
            {
                return path1[i];
            }
        }
    }
};