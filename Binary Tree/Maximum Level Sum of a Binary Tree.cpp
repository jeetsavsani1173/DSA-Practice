// problem link -->https://leetcode.com/problems/maximum-level-sum-of-a-binary-tree/

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
    int maxLevelSum(TreeNode* root) {
        int ans;
        int maxLsum=INT_MIN;
        
        queue<TreeNode*> q;
        q.push(root);
        int currLevel=1;
        while(!q.empty())
        {
            int lsize=q.size();
            int sum=0;
            
            for(int i=0;i<lsize;i++)
            {
                TreeNode* curr=q.front();
                q.pop();
                sum+=(curr->val);
                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);
            }
            
            if(maxLsum<sum)
            {
                maxLsum=sum;
                ans=currLevel;
            }
            currLevel++;
        }
        return ans;
    }
};