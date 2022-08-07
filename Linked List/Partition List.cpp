// problem link --> https://leetcode.com/problems/partition-list/

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
    ListNode* partition(ListNode* head, int x) {
        ListNode* dummy1=new ListNode(0);
        ListNode* tail1=dummy1;
        ListNode* dummy2=new ListNode(0);
        ListNode* tail2=dummy2;
        
        while(head){
            if(head->val<x){
                ListNode* node=new ListNode(head->val);
                tail1->next=node;
                tail1=tail1->next;
            }else{
                ListNode* node=new ListNode(head->val);
                tail2->next=node;
                tail2=tail2->next;
            }
            head=head->next;
        }
        tail1->next=dummy2->next;
        return dummy1->next;
    }
};