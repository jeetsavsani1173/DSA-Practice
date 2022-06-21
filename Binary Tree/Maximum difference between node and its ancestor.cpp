// problem link --> https://practice.geeksforgeeks.org/problems/maximum-difference-between-node-and-its-ancestor/1#

int ans;
int helper(Node* root)
{
    if(root==NULL) return INT_MAX;
    int lmin=helper(root->left);
    int rmin=helper(root->right);
    
    ans=max(ans,(root->data)-min(lmin,rmin));
    
    return min(root->data,min(lmin,rmin));
    
}
int maxDiff(Node* root)
{
    ans=INT_MIN;
    helper(root);
    return ans;
}