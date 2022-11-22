// problem link --> https://practice.geeksforgeeks.org/problems/sum-of-k-smallest-elements-in-bst3029/1

void dfs(Node* root,vector<int> &ans)
{
    if(root==NULL) return;
    
    ans.push_back(root->data);
    dfs(root->left,ans);
    dfs(root->right,ans);
}
int sum(Node* root, int k) 
{ 
  
    vector<int> ans;
    dfs(root,ans);
    sort(ans.begin(),ans.end());
    int sum=0;
    for(int i=0;i<k;i++)
        sum+=ans[i];
        
    return sum;
    
    
} 