// problem link -->  https://leetcode.com/problems/swapping-nodes-in-a-linked-list/

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
    int cnt1;
    ListNode* first;
    int find_size(ListNode* node)
    {
        int ans=0;
        while(node){
            ans++;
            node=node->next;
        }
        return ans;
    }
    void SWAPNODE(ListNode* second,int cnt2,int k)
    {
        if(second==NULL)
            return;
        
        SWAPNODE(second->next,cnt2-1,k);
        
        if(cnt1==k && cnt2==k)
            swap(first->val,second->val);
        
        cnt1++;
        first=first->next;
    }
    ListNode* swapNodes(ListNode* head, int k) {
        first=head;
        cnt1=1;
        int sz=find_size(head);
        if(sz==0) return head;
        
        SWAPNODE(head,sz,k);
        return head;
    }
};