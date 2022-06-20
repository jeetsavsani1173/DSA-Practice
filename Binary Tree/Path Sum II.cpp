// problem link --> https://leetcode.com/problems/path-sum-ii/

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
    vector<vector<int>> ans;
    void dfs(TreeNode* root,int currSum,vector<int> &temp,int &targetSum)
    {
        if(root==NULL) return;
        if(root->left==NULL && root->right==NULL){
            currSum+=(root->val);
            temp.push_back(root->val);
            if(currSum==targetSum)
                ans.push_back(temp);
            temp.pop_back();
            return;
        }
        currSum+=(root->val);
        temp.push_back(root->val);
        dfs(root->left,currSum,temp,targetSum);
        
        dfs(root->right,currSum,temp,targetSum);
        temp.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> temp;
        dfs(root,0,temp,targetSum);
        return ans;
    }
};