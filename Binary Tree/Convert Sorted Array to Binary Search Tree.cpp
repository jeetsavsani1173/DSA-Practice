// problem link --> https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/

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
    TreeNode* construct(vector<int>& nums,int lo,int hi)
    {
        if(lo>hi) return NULL;
        int mid=(lo+hi)/2;
        
        int data=nums[mid];
        TreeNode* lc=construct(nums,lo,mid-1);
        TreeNode* rc=construct(nums,mid+1,hi);
        
        TreeNode* node=new TreeNode(data,lc,rc);
        return node;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return construct(nums,0,nums.size()-1);
    }
};