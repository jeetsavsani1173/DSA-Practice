// problem link --> https://leetcode.com/problems/rotate-list/

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
    int Find_length(ListNode* node)
    {
        int ans=0;
        while(node)
        {
            ans++;
            node=node->next;
        }
        return ans;
    }
    ListNode* Find_pointer_after_k_nodes(ListNode* head,int x)
    {
        while(x!=1)
        {
            head=head->next;
            x--;
        }
        return head;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL || head->next==NULL)
            return head;
        int len=Find_length(head);
        k=k%len;
        ListNode* dummy=new ListNode(0);
        dummy->next=head;
        ListNode* first_point=Find_pointer_after_k_nodes(head,len-k);
        ListNode* last_point=Find_pointer_after_k_nodes(head,len);
        last_point->next=dummy->next;
        dummy->next=first_point->next;
        first_point->next=NULL;
        
        return dummy->next;
    }
};