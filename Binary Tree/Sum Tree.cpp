// problem link --> https://practice.geeksforgeeks.org/problems/sum-tree/1#

class Solution
{
    public:
    bool flag;
    int dfs(Node* root)
    {
        if(root==NULL) return 0;
        
        int lsum=dfs(root->left);
        int rsum=dfs(root->right);
        
        if(!(root->left==NULL && root->right==NULL))
        {
            if((lsum+rsum)!=(root->data)) 
            {
                flag=false;
            }
        }
        return lsum+rsum+(root->data);
    }
    bool isSumTree(Node* root)
    {
        flag=true;
        dfs(root);
        return flag;
    }
};
