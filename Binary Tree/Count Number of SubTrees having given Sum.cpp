// problem link --> https://practice.geeksforgeeks.org/problems/count-number-of-subtrees-having-given-sum/1#

int ans;
int helper(Node* root,int &target)
{
    if(root==NULL) return 0;
    int l=helper(root->left,target);
    int r=helper(root->right,target);
    if(l+r+(root->data)==target) ans++;
    
    return l+r+(root->data);
}
int countSubtreesWithSumX(Node* root, int X)
{
    ans=0;
	helper(root,X);
	return ans;
}