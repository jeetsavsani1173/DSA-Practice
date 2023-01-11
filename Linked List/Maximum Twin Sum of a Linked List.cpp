// problem link --> https://leetcode.com/problems/maximum-twin-sum-of-a-linked-list/

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
class Solution {
public:
    int ans;
    ListNode* left;
    void helper(ListNode* right)
    {
        if(right==NULL) return;
        
        helper(right->next);
        
        ans=max(ans,right->val+left->val);
        left=left->next;
    }
    int pairSum(ListNode* head) {
        ans=0;
        ListNode* right=head;
        left=head;
        helper(right);
        return ans;
    }
};