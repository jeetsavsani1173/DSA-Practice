// problem link --> https://leetcode.com/problems/remove-duplicates-from-sorted-list/

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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==NULL)
            return NULL;
        ListNode* temp=head;
        ListNode* ans_head=temp;
        while(temp->next)
        {
            if((temp->val)==(temp->next->val))
            {
                temp->next=temp->next->next; 
            }
            else
                temp=temp->next;
        }
        return ans_head;
    }
};