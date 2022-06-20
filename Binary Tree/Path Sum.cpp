// problem link --> https://leetcode.com/problems/path-sum/

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
    bool flag;
    void dfs(TreeNode* root,int currSum,int &targetSum)
    {
        if(root==NULL) return;
        if(root->left==NULL && root->right==NULL){
            currSum=currSum+(root->val);
            if(currSum==targetSum) flag=true;
            return;
        }
        currSum=currSum+(root->val);
        dfs(root->left,currSum,targetSum);
        dfs(root->right,currSum,targetSum);
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        dfs(root,0,targetSum);
        return flag;
    }
};