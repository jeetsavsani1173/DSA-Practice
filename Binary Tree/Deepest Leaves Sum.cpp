// problem link --> https://leetcode.com/problems/deepest-leaves-sum/

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
    int sum=0;
    int find_depth(TreeNode* root)
    {
        if(root==NULL) return 0;
        return 1+max(find_depth(root->left),find_depth(root->right));
    }
    void find_sum(TreeNode* root,int currDepth,int maxDepth)
    {
        if(root==NULL)
            return;
        if(root!=NULL && currDepth==maxDepth)
            sum+=(root->val);
        
        find_sum(root->left,currDepth+1,maxDepth);
        find_sum(root->right,currDepth+1,maxDepth);
    }
    int deepestLeavesSum(TreeNode* root) {
        int maxDepth=find_depth(root);
        find_sum(root,1,maxDepth);
        return sum;
    }
};