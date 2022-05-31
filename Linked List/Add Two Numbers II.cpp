// problem link --> https://leetcode.com/problems/add-two-numbers-ii/

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
    void reverse(ListNode* node)
    {
        if(node==NULL || node->next==NULL)
            return;
        reverse(node->next);
        node->next->next=node;
    }
    ListNode* reverseList(ListNode* head) {
        if(head==NULL || head->next==NULL) return head;
        int cnt=1;
        ListNode* tail=head;
        while(tail->next){
            tail=tail->next;
            cnt++;
        }
        reverse(head);
        head->next=NULL;
        return tail;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        l1=reverseList(l1);
        l2=reverseList(l2);
        
        ListNode* dummy=new ListNode(-1);
        ListNode* head=dummy;
        ListNode* tail=dummy;
        
        int carry=0;
        while(l1!=NULL || l2!=NULL || carry>0)
        {
            int d1=(l1==NULL)?0:l1->val;
            int d2=(l2==NULL)?0:l2->val;
            
            ListNode* temp=new ListNode((d1+d2+carry)%10);
            carry=(d1+d2+carry)/10;
            
            tail->next=temp;
            tail=tail->next;
            
            if(l1!=NULL) l1=l1->next;
            if(l2!=NULL) l2=l2->next;
        }
        
        return reverseList(dummy->next);
    }
};