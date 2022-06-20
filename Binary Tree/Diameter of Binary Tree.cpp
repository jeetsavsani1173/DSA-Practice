// problem link  -->> https://leetcode.com/problems/diameter-of-binary-tree/

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
public: // TC : O(N)
    int diameterOfBinaryTree(TreeNode* root) {
        int diameter=0;
        height(root,diameter);
        return diameter;
    }
    
    int height(TreeNode* node,int& diameter)
    {
        if(!node)
            return 0;
        
        int lh=height(node->left,diameter);
        int rh=height(node->right,diameter);
        
        diameter=max(diameter,lh+rh);
        
        return 1 + max(lh,rh);
    }
    
};

// second solution
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
public: // TC : O(N^2) Global or static variable Technique
    int height(TreeNode* root)
    {
        if(root==NULL) return 0;
        return 1+max(height(root->left),height(root->right));
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(root==NULL) return 0;
        
        int lh=height(root->left);
        int rh=height(root->right);
        
        int ld=diameterOfBinaryTree(root->left);
        int rd=diameterOfBinaryTree(root->right);
        
        return max(lh+rh,max(ld,rd));
    }
};

// third solution
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
public: // using Rerooting Technique.... pair<height,diameter> TC : O(N)
    pair<int,int> helper(TreeNode* root)
    {
        if(root==NULL) return {0,0};
        pair<int,int> left=helper(root->left);
        pair<int,int> right=helper(root->right);
        
        pair<int,int> rres;
        rres.first=1+max(left.first,right.first);
        rres.second=max(left.first+right.first,max(left.second,right.second));
        return rres;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        pair<int,int> ans=helper(root);
        return ans.second;
    }
};