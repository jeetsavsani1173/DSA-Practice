// problem link -->  https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/

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
            return head;
        ListNode* list_head=NULL;
        ListNode* list_tail=NULL;
        ListNode* first;
        ListNode* last;
        first=head;
        last=head;
        int cnt=0;
        int value;
        while(last!=NULL)
        {
            value=first->val;
            while(last!=NULL && (last->val)==value)
            {
                last=last->next;
                cnt++;
            }
            
            if(cnt==1)
            {
                ListNode *newnode=new ListNode(value);
                if(list_head==NULL)
                {
                    list_head=newnode;
                    list_tail=newnode;
                }
                else
                {
                    list_tail->next=newnode;
                    list_tail=newnode;
                }
            }
            cnt=0;
            first=last;
        }
        if(cnt==1)
        {
                ListNode *newnode=new ListNode(value);
                if(list_head==NULL)
                {
                    list_head=newnode;
                    list_tail=newnode;
                }
                else
                {
                    list_tail->next=newnode;
                    list_tail=newnode;
                }
        }
        
        return list_head;
    }
};