// problem link --> https://leetcode.com/problems/maximum-product-of-splitted-binary-tree/

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
static int M=1e9+7;
class Solution {
public:
    long long ans,total_sum;
    void find_totalSum(TreeNode* root,long long &sum)
    {
        if(root==NULL) return;
        sum+=(root->val);
        find_totalSum(root->left,sum);
        find_totalSum(root->right,sum);
    }
    long long SubTreeSum(TreeNode* root)
    {
        if(root==NULL) return 0ll;
        
        int lsum=SubTreeSum(root->left);
        int rsum=SubTreeSum(root->right);
        
        ans=max({ans,lsum*(total_sum-lsum),rsum*(total_sum-rsum)});
        
        return lsum+rsum+(root->val);
    }
    int maxProduct(TreeNode* root) {
        ans=0,total_sum=0;
        find_totalSum(root,total_sum);
        
        SubTreeSum(root);
        return ans%M;
    }
};