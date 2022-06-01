// problem link --> https://leetcode.com/problems/odd-even-linked-list/

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
    ListNode* oddEvenList(ListNode* head) {
        ListNode* firstHead=new ListNode(-1);
        ListNode* secondHead=new ListNode(-1);
        ListNode* first=firstHead;
        ListNode* second=secondHead;
        
        while(head!=NULL){
            first->next=head;
            first=head;
            head=head->next;
            
            if(head!=NULL){
                second->next=head;
                second=head;
                head=head->next;
            }
        }
        
        first->next=secondHead->next;
        second->next=NULL;
        return firstHead->next;
    }
};