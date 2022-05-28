// problem link --> https://leetcode.com/problems/reverse-linked-list-ii/

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
    void modifiedReverse(ListNode* second, int left, int right,int cnt2)
    {
        if(second==NULL) return;
        
        modifiedReverse(second->next,left,right,cnt2+1);
        if(cnt2==right)
        {
            while(cnt1<left)
            {
                cnt1++;
                first=first->next;
            }
        }
        
        if(cnt1<cnt2 && cnt1>=left && cnt2<=right)
            swap(first->val,second->val);
            
        if(cnt1<cnt2 && cnt1>=left && cnt2<=right){
            cnt1++;
            first=first->next;
        }
    }
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(left==right)
            return head;
        cnt1=1;
        first=head;
        modifiedReverse(head,left,right,1);
        return head;
    }
};