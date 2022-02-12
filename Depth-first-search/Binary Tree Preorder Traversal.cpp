// problem link -->> https://leetcode.com/problems/binary-tree-preorder-traversal/

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
public:// Recursive solution
    void RpreorderTraversal(TreeNode *root,vector<int> &ans)
    {
        if(root)
        {
            ans.push_back(root->val);
            RpreorderTraversal(root->left,ans);
            RpreorderTraversal(root->right,ans);
        }
            
    }
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        RpreorderTraversal(root,ans);
        
        return ans;
    }
};


// itarative solution.
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> pre;
        
        stack<TreeNode*> st;
        
        TreeNode *curr=root;
        
        while(!st.empty() || curr!=NULL)
        {
            if(curr)
            {
                pre.push_back(curr->val);
                st.push(curr);
                curr=curr->left;
            }
            else
            {
                curr=st.top();
                st.pop();
                curr=curr->right;
            }
        }
        
        return pre;
        
    }
};