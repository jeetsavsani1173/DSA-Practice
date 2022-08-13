// problem link -->     https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    void  find_path(TreeNode* root, TreeNode* p,vector<TreeNode*> &path)
    {
        if(root==NULL) return;
        
        if(root==p){
            path.push_back(root);
            return;
        }
        path.push_back(root);
        if(root->val>p->val)
            find_path(root->left,p,path);
        else
            find_path(root->right,p,path);
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> first;
        find_path(root,p,first);
        vector<TreeNode*> second;
        find_path(root,q,second);
        
        int i=0;
        for(;i<first.size() && i<second.size();i++){
            if(first[i]!=second[i])
                return first[i-1];
        }
        
        if(first.size()<second.size()) return first[first.size()-1];
        else return second[second.size()-1];
    }
};