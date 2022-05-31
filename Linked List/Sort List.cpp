// problem link --> https://leetcode.com/problems/sort-list/

// first solution
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

// second solution
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
    ListNode* Find_mid_node(ListNode* head)
    {
        ListNode* fast=head;
        ListNode* slow=head;
        ListNode* prev=NULL;
        
        while(fast!=NULL && fast->next!=NULL)
        {
            prev=slow;
            slow=slow->next;
            fast=fast->next->next;
        }
        if(fast==NULL) return prev;
        return slow;
    }
    ListNode* sortList(ListNode* head) {
        if(head==NULL || head->next==NULL)
            return head;
        
        ListNode* mid=Find_mid_node(head);
        ListNode* midNext=mid->next;
        mid->next=NULL;
        
        ListNode* left=sortList(head);
        ListNode* right=sortList(midNext);
        
        return mergeTwoLists(left,right);
    }
};