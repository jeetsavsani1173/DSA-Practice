// problem link --> https://leetcode.com/problems/linked-list-in-binary-tree/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    bool isSubPathHelper(ListNode* head,TreeNode* root)
    {
        if(head==NULL) return true; // our whole LL is traverse and found..
        if(root==NULL) return false;// our LL is still remain..
        
        if((root->val)==(head->val)){
            if(isSubPathHelper(head->next,root->left)) return true;
            if(isSubPathHelper(head->next,root->right)) return true;
        }
        return false;
    }
    bool isSubPath(ListNode* head, TreeNode* root) {
        if(head==NULL) return true; // empty List
        if(root==NULL) return false; // empty tree
        
        if(head->val==root->val){
            if(isSubPathHelper(head,root))
                return true;
        }
        return isSubPath(head,root->left) || isSubPath(head,root->right);
    }
};