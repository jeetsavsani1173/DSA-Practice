// problem link  -->https://practice.geeksforgeeks.org/problems/burning-tree/1

class Solution {
  public:
    int ans;
    int maxDepth(Node* root,Node* blocker)
    {
        if(root==NULL || root==blocker) return 0;
        return 1+max(maxDepth(root->left,blocker),maxDepth(root->right,blocker));
    }
    int helper(Node* root,int target)
    {
        if(root==NULL) return -1;
        if(root->data==target){
            ans=max(ans,maxDepth(root,NULL));
            return 1;
        }
        
        int left=helper(root->left,target);
        if(left>0){
            ans=max(ans,left+maxDepth(root,root->left));
            return left+1;
        }
        
        int right=helper(root->right,target);
        if(right>0){
            ans=max(ans,right+maxDepth(root,root->right));
            return right+1;
        }
        return -1;
    }
    int minTime(Node* root, int target) 
    {
        ans=INT_MIN;
        helper(root,target);
        return ans-1;
    }
};