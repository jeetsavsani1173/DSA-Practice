// problem link --> https://practice.geeksforgeeks.org/problems/remove-half-nodes/1#

Node* dfs(Node* root)
{
    if(root==NULL) return NULL;
    if(root->left==NULL && root->right==NULL) return root;
    if(root->left!=NULL && root->right!=NULL){
        root->left=dfs(root->left);
        root->right=dfs(root->right);
        return root;
    }
    if(root->left==NULL){
        return dfs(root->right);
    }else{
        return dfs(root->left);
    }
}
Node *RemoveHalfNodes(Node *root)
{
   return dfs(root);
}