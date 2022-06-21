// problem link --> https://practice.geeksforgeeks.org/problems/transform-to-sum-tree/1#

class Solution {
  public:
  
    int dfs(Node* node)
    {
        if(node==NULL) return 0;
        
        int temp=node->data;
        int lsum=dfs(node->left);
        int rsum=dfs(node->right);
        
        node->data=lsum+rsum;
        
        return lsum+rsum+temp;
    }
    void toSumTree(Node *node)
    {
        dfs(node);
    }
};