// problem link --> https://practice.geeksforgeeks.org/problems/unique-rows-in-boolean-matrix/1

struct Node
{
    Node *left;
    Node *right;
};

vector<vector<int>> ans;
Node *root = new Node();
void dfs(Node *curr, vector<int> &temp)
{
    if (curr == NULL)
        return;
    if (curr->left == NULL && curr->right == NULL)
    {
        ans.push_back(temp);
        return;
    }

    if (curr->left != NULL)
    {
        temp.push_back(0);
        dfs(curr->left, temp);
        temp.pop_back();
    }
    if (curr->right != NULL)
    {
        temp.push_back(1);
        dfs(curr->right, temp);
        temp.pop_back();
    }
}

void insert(int *arr, int col)
{
    Node *curr = root;
    for (int j = 0; j < col; j++)
    {
        if (arr[j] == 1)
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

/*You are required to complete this function*/
vector<vector<int>> uniqueRow(int M[MAX][MAX], int row, int col)
{
    for (int i = 0; i < row; i++)
    {
        insert(M[i], col);
    }
    vector<int> temp;
    dfs(root, temp);
    return ans;
}