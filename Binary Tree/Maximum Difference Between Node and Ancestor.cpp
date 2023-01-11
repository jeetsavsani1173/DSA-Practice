// problem link --> https://leetcode.com/problems/maximum-difference-between-node-and-ancestor/description/

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
    int diff;
    pair<int,int> dfs(TreeNode* root)
    {
        if(root==NULL) return {INT_MAX,INT_MIN};
        if(root->left==NULL && root->right==NULL) return {root->val,root->val};

        pair<int,int> lans=dfs(root->left);
        pair<int,int> rans=dfs(root->right);

        int mn=min(lans.first,rans.first);
        int mx=max(lans.second,rans.second);

        diff=max(diff,max(abs(mn-root->val),abs(mx-root->val)));

        mn=min(mn,root->val);
        mx=max(mx,root->val);

        return {mn,mx};
    }
    int maxAncestorDiff(TreeNode* root) {
        diff=0;
        dfs(root);
        return diff;
    }
};