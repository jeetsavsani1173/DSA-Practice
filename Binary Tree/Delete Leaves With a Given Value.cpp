// problem link --> https://leetcode.com/problems/delete-leaves-with-a-given-value/

class Solution {
public:
    TreeNode* helper(TreeNode* root,int target)
    {
        if(root==NULL) return NULL;
        
        root->left=helper(root->left,target);
        root->right=helper(root->right,target);
        
        if(root->left==NULL && root->right==NULL && root->val==target)
            return NULL;
        
        return root;
    }
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        return helper(root,target);
    }
};