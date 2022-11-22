// problem link --> https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/

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
    map<int,vector<pair<int,int>>> mp;
    void dfs(TreeNode* root,int x,int y)
    {
        if(root==NULL) return;
        mp[y].push_back({x,root->val});
        
        dfs(root->left,x+1,y-1);
        dfs(root->right,x+1,y+1);
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        dfs(root,0,0);
        
        for(auto it:mp)
        {
            sort(it.second.begin(),it.second.end());
            vector<int> temp;
            for(auto it1:it.second)
            {
                temp.push_back(it1.second);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};