// problem link --> https://practice.geeksforgeeks.org/problems/flatten-binary-tree-to-linked-list/1

class Solution
{
public:
    Node *buildLL(Node *root)
    {
        if (root == NULL)
            return NULL;
        if (root->left == NULL && root->right == NULL)
            return root;
        if (root->left == NULL && root->right != NULL)
        {
            root->right = buildLL(root->right);
            return root;
        }
        if (root->left != NULL && root->right == NULL)
        {
            root->right = buildLL(root->left);
            root->left = NULL;
            return root;
        }
        Node *l1 = buildLL(root->left);
        Node *curr = l1;
        while (curr->right != NULL)
            curr = curr->right;

        Node *l2 = buildLL(root->right);
        curr->right = l2;
        root->left = NULL;
        root->right = l1;
        return root;
    }
    void flatten(Node *root)
    {
        if (root == NULL)
            return;
        root = buildLL(root);
    }
};