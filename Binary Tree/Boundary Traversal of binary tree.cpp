// problem link --> https://practice.geeksforgeeks.org/problems/boundary-traversal-of-binary-tree/0

class Solution
{
public:
    void addLeftB(Node *root, vector<int> &ans)
    {
        if (root == NULL)
            return;
        if (root->left == NULL && root->right == NULL)
            return;
        ans.push_back(root->data);

        if (root->left)
            addLeftB(root->left, ans);
        else
            addLeftB(root->right, ans);
    }

    void addLeaf(Node *root, vector<int> &ans)
    {
        if (root == NULL)
            return;
        addLeaf(root->left, ans);
        addLeaf(root->right, ans);
        if (root->left == NULL && root->right == NULL)
            ans.push_back(root->data);
    }

    void addRightB(Node *root, vector<int> &ans)
    {
        if (root == NULL)
            return;
        // if(root->left==NULL && root->right==NULL) return;

        if (root->right)
            addRightB(root->right, ans);
        else
            addRightB(root->left, ans);

        ans.push_back(root->data);
    }

    vector<int> boundary(Node *root)
    {
        vector<int> ans;
        if (root == NULL)
            return ans;
        if (root->left == NULL && root->right == NULL)
        {
            return {root->data};
        }

        ans.push_back(root->data);
        if (root->left)
            addLeftB(root->left, ans);
        addLeaf(root, ans);
        vector<int> temp;
        if (root->right)
            addRightB(root->right, temp);

        for (int i = 1; i < (temp.size()); i++)
        {
            ans.push_back(temp[i]);
        }
        return ans;
    }
};