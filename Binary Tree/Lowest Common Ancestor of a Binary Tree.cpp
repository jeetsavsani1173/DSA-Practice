// problem link --> https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/

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
    bool find_path(TreeNode* root, TreeNode* p,vector<TreeNode*> &path)
    {
        if(root==NULL) return false;
        
        path.push_back(root);
        if(root==p) return true;
        bool left=find_path(root->left,p,path);
        bool right=find_path(root->right,p,path);
        if(left||right) return true;
        path.pop_back();
        return false;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> path1;
        find_path(root,p,path1);
        vector<TreeNode*> path2;
        find_path(root,q,path2);
//         for(auto it:path1)
//             cout<<it->val<<" ";
//         cout<<endl;
        
//         for(auto it:path2)
//             cout<<it->val<<" ";
//         cout<<endl;
        int i;
        for(i=1;i<min(path1.size(),path2.size());i++){
            if(path1[i]!=path2[i])
                return path1[i-1];
        }
        return (path1.size()>path2.size())?(path1[i-1]):(path2[i-1]);
    }
};