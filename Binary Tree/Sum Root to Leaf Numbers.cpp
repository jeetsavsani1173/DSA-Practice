// problem link --> https://leetcode.com/problems/sum-root-to-leaf-numbers/

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
    void dfs(TreeNode* root,int currSum)
    {
        if(root==NULL) return;
        if(root->left==NULL && root->right==NULL){
            currSum=currSum*10+(root->val);
            sum+=currSum;
            return;
        }
        
        currSum=currSum*10+(root->val);
        dfs(root->left,currSum);
        dfs(root->right,currSum);
    }
    int sumNumbers(TreeNode* root) {
        dfs(root,0);
        return sum;
    }
};