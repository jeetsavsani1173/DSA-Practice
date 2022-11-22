// problem link --> https://leetcode.com/problems/pseudo-palindromic-paths-in-a-binary-tree/

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
    int ans;
    bool isPalindrome(map<int,int> &mp,int countNodes){
        if(countNodes&1){
            int count=0;
            for(auto it:mp){
                if(it.second&1) count++;
            }
            
            if(count>1) return false;
        }else{
            int count=0;
            for(auto it:mp){
                if(it.second&1) count++;
            }
            
            if(count>0) return false;
        }
        return true;
    }
    void dfs(TreeNode* root,int &count,map<int,int> &mp){
        if(root==NULL) return;
        if(root->left==NULL && root->right==NULL){
            count++;
            mp[root->val]++;
            if(isPalindrome(mp,count)) ans++;
            mp[root->val]--;
            count--;
            return;
        }
        count++;
        mp[root->val]++;
        dfs(root->left,count,mp);
        dfs(root->right,count,mp);
        mp[root->val]--;
        count--;
    }
    int pseudoPalindromicPaths (TreeNode* root) {
        ans=0;
        int countNodes=0;
        map<int,int> mp;
        dfs(root,countNodes,mp);
        return ans;
    }
};