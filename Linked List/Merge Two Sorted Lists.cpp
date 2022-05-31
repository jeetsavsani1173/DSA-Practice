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

//second solution

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
    ListNode* mergeTwoLists(ListNode* head1, ListNode* head2) {
        ListNode* head;
        ListNode* tail;
        ListNode* dummy=new ListNode(-1);
        head=tail=dummy;

        // merge to sorted LL..
        while(head1!=NULL && head2!=NULL){
            if(head1->val<head2->val){
                tail->next=head1;
                head1=head1->next;
                tail=tail->next;
            }
            else{
                tail->next=head2;
                head2=head2->next;
                tail=tail->next;
            }
        }

        if(head1!=NULL){
            tail->next=head1;
        }
        if(head2!=NULL){
            tail->next=head2;
        }

        return dummy->next;
    }
};