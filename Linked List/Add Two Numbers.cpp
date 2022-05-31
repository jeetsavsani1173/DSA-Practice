// problem link --> https://leetcode.com/problems/add-two-numbers/

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy=new ListNode(0);
        ListNode* temp=NULL;
        dummy->next=temp;
        int sum=0,carry=0;
        while(l1!=NULL || l2!=NULL)
        {
            sum=0;
            if(l1!=NULL)
            {
                sum+=(l1->val);
                l1=l1->next;
            }
            if(l2!=NULL)
            {
                sum+=(l2->val);
                l2=l2->next;
            }
            sum+=carry;
            
            int node_val=sum%10;
            carry=sum/10;
            
            ListNode* newnode=new ListNode(node_val);
            
            if(temp==NULL)
            {
                dummy->next=newnode;
                temp=newnode;
            }
            else
            {
                temp->next=newnode;
                temp=temp->next;
            }
        }
        if(carry!=0)
        {
            ListNode* newnode=new ListNode(carry);
            
            if(temp==NULL)
            {
                dummy->next=newnode;
                temp=newnode;
            }
            else
            {
                temp->next=newnode;
                temp=temp->next;
            }
        }
        
        return dummy->next;
    }
};


// second solution
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
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
        
        return dummy->next;
    }
};