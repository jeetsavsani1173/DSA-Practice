// problem link --> https://leetcode.com/problems/insufficient-nodes-in-root-to-leaf-paths/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool helper(TreeNode* root,int sum,int limit)
    {
        if(root==NULL) return false;
        if(root->left==NULL && root->right==NULL)
        {
            sum+=(root->val);
            return (sum>=limit);
        }
        sum+=(root->val);
        int left=helper(root->left,sum,limit);
        if(left==false) root->left=NULL;
        
        int right=helper(root->right,sum,limit);
        if(right==false) root->right=NULL;
        
        return left||right;
    }
    TreeNode* sufficientSubset(TreeNode* root, int limit) {
        if(helper(root,0,limit)==false) root=NULL;
        return root;
    }
};