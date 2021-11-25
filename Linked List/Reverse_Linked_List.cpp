// problem Link->>>>>https://leetcode.com/problems/reverse-linked-list/


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

// first solution 
class Solution {
public:// itarative solution
    ListNode* reverseList(ListNode* head) {
        ListNode* p=head;
        ListNode* q=NULL;
        while(p)
        {
            ListNode *temp=p->next;
            p->next=q;
            q=p;
            p=temp;
        }
        
        return q;
    }
};

// second solution

class Solution {
public:// Recursive solution
    ListNode* reverseList(ListNode* head) {
        if(head==NULL || head->next==NULL)
            return head;
        
        ListNode *restofList=reverseList(head->next);
        
        head->next->next=head;
        
        head->next=NULL;
        
        return restofList;
    }
};