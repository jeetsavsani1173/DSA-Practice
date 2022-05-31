// problem link --> https://leetcode.com/problems/remove-nth-node-from-end-of-list/

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
    int find_size(ListNode* node)
    {
        int ans=0;
        while(node) node=node->next,ans++;
        return ans;
    }
    void helper(ListNode* node,int cnt,int k)
    {
        if(node==NULL) return;
        helper(node->next,cnt-1,k);
        if(cnt==k+1)
            node->next=node->next->next;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int sz=find_size(head);
        if(sz==0) return head;
        if(sz==n) return head->next;
        helper(head,sz,n);
        return head;
    }
};