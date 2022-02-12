// problem link -->> https://leetcode.com/problems/binary-tree-inorder-traversal/

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
class Solution { // Recursive approach.
public:
    void RinorderTraversal(TreeNode *root,vector<int> &ans)
    {
        if(root)
        {
            RinorderTraversal(root->left,ans);
            ans.push_back(root->val);
            RinorderTraversal(root->right,ans);
        }
            
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        RinorderTraversal(root,ans);
        
        return ans;
    }
};


// itarative inorder trav
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        
        stack<TreeNode*> st;
        //st.push(root);
        
        TreeNode *curr=root;
        
        while(!st.empty() || curr!=NULL)
        {
            if(curr)
            {
                st.push(curr);
                curr=curr->left;
            }
            else
            {
                curr=st.top(); 
                st.pop();
                ans.push_back(curr->val);
                curr=curr->right;
            }
        }
        
        return ans;
        
    }
};