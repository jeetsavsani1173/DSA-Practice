// problem link --> https://leetcode.com/problems/merge-two-sorted-lists/

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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1==NULL)
            return list2;
        if(list2==NULL)
            return list1;
        ListNode* first=list1;
        ListNode* second=list2;
        ListNode* final_head;
        ListNode* final_tail;
        if(first->val<second->val)
        {
            ListNode *node=new ListNode(first->val);
            node->next=NULL;
            final_head=final_tail=node;
            first=first->next;
        }
        else
        {
            ListNode* node=new ListNode(second->val);
            node->next=NULL;
            final_head=final_tail=node;
            second=second->next;
        }
        while(first!=NULL && second!=NULL)
        {
            if(first->val<second->val)
            {
                ListNode* node=new ListNode(first->val);
                node->next=NULL;
                final_tail->next=node;
                final_tail=final_tail->next;
                first=first->next;
            }
            else
            {
                ListNode* node=new ListNode(second->val);
                node->next=NULL;
                final_tail->next=node;
                final_tail=final_tail->next;
                second=second->next;
            }
        }
        while(first!=NULL)
        {
            ListNode* node=new ListNode(first->val);
            node->next=NULL;
            final_tail->next=node;
            final_tail=final_tail->next;
            first=first->next;
        }
        while(second!=NULL)
        {
            ListNode* node=new ListNode(second->val);
            node->next=NULL;
            final_tail->next=node;
            final_tail=final_tail->next;
            second=second->next;
        }
        
        return final_head;
    }
};