// problem link --> https://leetcode.com/problems/add-one-row-to-tree/

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
    void dfs(TreeNode* root,int currDepth,int depth,int val)
    {
        if(root==NULL) return;
        
        if(currDepth+1==depth){
            TreeNode* newLeft=new TreeNode(val);
            TreeNode* newRight=new TreeNode(val);
            newLeft->left=root->left;
            newRight->right=root->right;
            root->left=newLeft;
            root->right=newRight;
            return;
        }
        
        dfs(root->left,currDepth+1,depth,val);
        dfs(root->right,currDepth+1,depth,val);
    }
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth==1){
            TreeNode* node=new TreeNode(val);
            node->left=root;
            return node;
        }
        
        dfs(root,1,depth,val);
        return root;
    }
};