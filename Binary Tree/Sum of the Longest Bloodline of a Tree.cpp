// problem link --> https://practice.geeksforgeeks.org/problems/sum-of-the-longest-bloodline-of-a-tree/1#

class Solution
{
public:
    int ans;
    int find_height(Node* root)
    {
        if(root==NULL) return 0;
        return 1+max(find_height(root->left),find_height(root->right));
    }
    void dfs(Node* root,int CurrSum,int CurrH,int &height)
    {
        if(root==NULL) return;
        CurrSum+=(root->data);
        if(CurrH==height) ans=max(ans,CurrSum);
        
        dfs(root->left,CurrSum,CurrH+1,height);
        dfs(root->right,CurrSum,CurrH+1,height);
    }
    int sumOfLongRootToLeafPath(Node *root)
    {
        ans=INT_MIN;
        int height=find_height(root);
        dfs(root,0,1,height);
        return ans;
    }
};