// problem link --> https://leetcode.com/problems/reorder-list/

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
    ListNode* Find_middle(ListNode* head)
    {
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }
    ListNode* reverse(ListNode* head)
    {
        ListNode* curr=head;
        ListNode* prev=NULL;
        
        while(curr!=NULL)
        {
            ListNode* ahead=curr->next;
            curr->next=prev;
            prev=curr;
            curr=ahead;
        }
        
        return prev;
    }
    void reorderList(ListNode* head) {
        ListNode* mid=Find_middle(head);
        ListNode* l2=reverse(mid->next);
        mid->next=NULL;
        ListNode* l1=head;
        
        ListNode* dummy=new ListNode(-1);
        ListNode* tail=dummy;
        while(l1!=NULL){
            tail->next=l1;
            tail=tail->next;
            l1=l1->next;
            if(l2!=NULL){
                tail->next=l2;
                tail=tail->next;
                l2=l2->next;
            }
        }
        head=dummy->next;
    }
};