// problem link --> https://practice.geeksforgeeks.org/problems/kth-ancestor-in-a-tree/1

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
int kthAncestor(Node *root, int k, int node)
{
    bool flag = false;
    vector<Node *> path;
    dfs(root, node, path, flag);

    reverse(path.begin(), path.end());

    if (k < path.size())
    {
        return path[k]->data;
    }
    else
    {
        return -1;
    }
}