// problem link --> https://practice.geeksforgeeks.org/problems/count-bst-nodes-that-lie-in-a-given-range/1#

class Solution{
public:
    int ans;    
    void helper(Node* root,int l,int h)
    {
        if(!root) return;
        if(l<=root->data && root->data<=h) ans++;
        helper(root->left,l,h);
        helper(root->right,l,h);
    }
    int getCount(Node *root, int l, int h)
    {
        ans=0;
        helper(root,l,h);
        return ans;
    }
};