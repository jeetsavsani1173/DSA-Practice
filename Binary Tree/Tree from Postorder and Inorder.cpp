// problem link --> https://practice.geeksforgeeks.org/problems/tree-from-postorder-and-inorder/1

int find_index(int a[], int s, int e, int t)
{
    for (int i = s; i <= e; i++)
    {
        if (a[i] == t)
            return i;
    }
}
Node *buildTree(int in[], int post[], int n, int s1, int e1, int s2, int e2)
{
    if (s1 > e1 || s2 > e2)
    {
        return NULL;
    }
    int index = find_index(in, s1, e1, post[e2]);
    Node *curr = new Node(post[e2]);
    int mid = s2 + (index - s1);
    curr->left = buildTree(in, post, n, s1, index - 1, s2, mid - 1);
    curr->right = buildTree(in, post, n, index + 1, e1, mid, e2 - 1);
    return curr;
}
Node *buildTree(int in[], int post[], int n)
{
    return buildTree(in, post, n, 0, n - 1, 0, n - 1);
}