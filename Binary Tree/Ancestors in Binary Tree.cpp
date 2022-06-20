// problem link --> https://practice.geeksforgeeks.org/problems/ancestors-in-binary-tree/1#

class Solution{
  public:
  vector<int> ans;
    void dfs(Node* root,int target,vector<int> &path)
    {
        if(root==NULL) return;
        if(root->data==target)
        {
            ans=path;
            return;
        }
        
        path.push_back(root->data);
        dfs(root->left,target,path);
        dfs(root->right,target,path);
        path.pop_back();
        
    }
    vector<int> Ancestors(struct Node *root, int target)
    {
        if(root==NULL) return ans;
        vector<int> path;
        dfs(root,target,path);
        reverse(ans.begin(),ans.end());
        return ans;
    }
};