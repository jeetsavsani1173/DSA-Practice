// problem link --> https://leetcode.com/problems/cousins-in-binary-tree/

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
public: // using DFS
    int xLevel=0,yLevel=0,xParent=-1,yParent=-1;
    void dfs(TreeNode* root,int x,int y,int currLevel)
    {
        if(root==NULL) return;
        
        if(root->val==x) xLevel=currLevel;
        if(root->val==y) yLevel=currLevel;
        
        if(root->left){
            if(root->left->val==x) xParent=root->val;
            if(root->left->val==y) yParent=root->val;
        }
        
        if(root->right){
            if(root->right->val==x) xParent=root->val;
            if(root->right->val==y) yParent=root->val;
        }
        dfs(root->left,x,y,currLevel+1);
        dfs(root->right,x,y,currLevel+1);
    }
    bool isCousins(TreeNode* root, int x, int y) {
        dfs(root,x,y,0);
        
        if(x==y) return false;
        if(xLevel!=yLevel) return false;
        if(xParent==yParent) return false;
        return true;
    }
};