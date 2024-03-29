// problem link -->> https://leetcode.com/problems/balanced-binary-tree/

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
public: // TC:O(N) SP:O(N)
    // if tree is balanced than function return(Height of a trre) othervise it will return(-1).
    int dfsHeight(TreeNode* root)
    {
        if(root==NULL)
            return 0;
        
        int leftHeight=dfsHeight(root->left);
        if(leftHeight==-1)  return -1;
        int rightHeight=dfsHeight(root->right);
        if(rightHeight==-1) return -1;
        
        if(abs(leftHeight-rightHeight)>1)
            return -1;
        
        return 1 + max(leftHeight,rightHeight);
    }
    bool isBalanced(TreeNode* root) {
        if(dfsHeight(root)==-1)
            return 0;
        else
            return 1;
    }
};

// second solution
class Solution {
public: // using rerooting Technique Tc : O(N) pair<int,bool> = pair<height,isbalance>
    pair<int,bool> helper(TreeNode* root)
    {
        if(root==NULL) return {0,true};
        pair<int,bool> left=helper(root->left);
        pair<int,bool> right=helper(root->right); 
        
        pair<int,bool> rres;
        rres.second=(abs(left.first-right.first)<2 && left.second && right.second);
        rres.first=1+max(left.first,right.first);
        
        return rres;
    }
    bool isBalanced(TreeNode* root) {
        pair<int,bool> ans=helper(root);
        return ans.second;
    }
};

//third solution

class Solution {
public: // TC:O(N^2) SP:O(N)
    int depth (TreeNode *root) {
        if (root == NULL) return 0;
        return max (depth(root -> left), depth (root -> right)) + 1;
    }

    bool isBalanced (TreeNode *root) {
        if (root == NULL) return true;
        
        int left=depth(root->left);
        int right=depth(root->right);
        
        return abs(left - right) <= 1 && isBalanced(root->left) && isBalanced(root->right);
    }
};