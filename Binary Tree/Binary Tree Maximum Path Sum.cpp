// problem link  -->>  https://leetcode.com/problems/binary-tree-maximum-path-sum/

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
    int maxPathSum(TreeNode* root) {
        int maxi=INT_MIN;
        maxPathDown(root,maxi);
        return maxi;
    }
    int maxPathDown(TreeNode* node,int &maxi)
    {
        if(node==NULL) return 0;
        int left=max(0,maxPathDown(node->left,maxi));
        int right=max(0,maxPathDown(node->right,maxi));
        maxi=max(maxi, left + (node->val) + right);
        return (node->val + max(left,right));
    }
};

// second solution
class Solution {
public:
    int ans;
    int helper(TreeNode* root)
    {
        if(root==NULL) return 0;
        int lsum=helper(root->left);
        int rsum=helper(root->right);
        
        ans=max(ans,lsum+rsum+(root->val));
        
        return max(0,(root->val)+max(lsum,rsum));
    }
    int maxPathSum(TreeNode* root) {
        ans=INT_MIN;
        helper(root);
        return ans;
    }
};