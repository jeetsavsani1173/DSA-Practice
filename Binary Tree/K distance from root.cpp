// problem link --> https://practice.geeksforgeeks.org/problems/k-distance-from-root/1#

void dfs(Node* root,int level,int k,vector<int>&ans)
{
    if(root==NULL) return;
    if(level==k) ans.push_back(root->data);
    
    dfs(root->left,level+1,k,ans);
    dfs(root->right,level+1,k,ans);
}
vector<int> Kdistance(struct Node *root, int k)
{
  vector<int> ans;
  dfs(root,0,k,ans);
  return ans;
}

