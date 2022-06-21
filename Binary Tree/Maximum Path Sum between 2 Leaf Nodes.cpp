// problem link --> https://practice.geeksforgeeks.org/problems/maximum-path-sum/1#

class Solution {
public:
    int ans=INT_MIN;
    int dfs(Node* root)
    {
        if(root==NULL) return 0;
        if(root->left==NULL && root->right==NULL) return (root->data);
        int lsum=dfs(root->left);
        int rsum=dfs(root->right);
        
        if(root->left==NULL) return rsum+(root->data);
        if(root->right==NULL) return lsum+(root->data);
        ans=max(ans,lsum+rsum+(root->data));
        return (root->data)+max(lsum,rsum);
    }
    int maxPathSum(Node* root)
    {
        ans=INT_MIN;
        int temp=dfs(root);
        if(root->left==NULL || root->right==NULL)
             ans=max(ans,temp);
        return ans;
    }
};