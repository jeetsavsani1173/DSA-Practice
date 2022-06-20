// problem link --> https://leetcode.com/problems/binary-tree-tilt/

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
    int Total_Tilt;
    int subTreeSum(TreeNode* root)
    {
        if(root==NULL) return 0;
        int l=subTreeSum(root->left);
        int r=subTreeSum(root->right);
        
        Total_Tilt+=(abs(l-r));
        return l+r+(root->val);
    }
    int findTilt(TreeNode* root) {
        subTreeSum(root);
        return Total_Tilt;
    }
};