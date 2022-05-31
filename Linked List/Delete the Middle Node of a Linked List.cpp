// problem link --> https://leetcode.com/problems/delete-the-middle-node-of-a-linked-list/

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
    int find_size(ListNode* node)
    {
        int ans=0;
        while(node) node=node->next,ans++;
        return ans;
    }
    ListNode* deleteMiddle(ListNode* head) {
        int sz=find_size(head);
        if(sz==0 || sz==1)
            return NULL;
        ListNode* node=head;
        int cnt=1;
        while(cnt<sz/2)
        {
            cnt++;
            node=node->next;
        }
        node->next=node->next->next;
        return head;
    }
};

// second solution 
// constant space and only one traversal
class Solution {
public:
    
    ListNode* deleteMiddle(ListNode* head) {
        if(head==NULL || head->next==NULL) return NULL;
        ListNode* slow=head;
        ListNode* fast=head;
        
        while(fast!=NULL && fast->next!=NULL){
            fast=fast->next->next;
            if(fast!=NULL && fast->next!=NULL)
                slow=slow->next;
        }
        slow->next=slow->next->next;
        return head;
    }
};