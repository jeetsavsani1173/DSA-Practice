// problem link --> https://leetcode.com/problems/sort-list/

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
    ListNode* Find_min_node(ListNode* head,ListNode* tail)
    {
        ListNode* fast=head;
        ListNode* slow=head;
        
        while(fast!=tail && fast->next!=tail)
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }
    ListNode* helper(ListNode* head,ListNode* tail)
    {
        if(head==tail)
        {
            ListNode* node=new ListNode(head->val);
            return node;
        }
        
        ListNode* mid=Find_min_node(head,tail);
        ListNode* fsh=helper(head,mid);
        ListNode* ssh=helper(mid->next,tail);
        
        ListNode* final_list=mergeTwoLists(fsh,ssh);
        return final_list;
    }
    ListNode* sortList(ListNode* head) {
        ListNode* tail=head;
        if(tail==NULL)
            return head;
        while(tail->next!=NULL)
            tail=tail->next;
        
        return helper(head,tail);
    }
};