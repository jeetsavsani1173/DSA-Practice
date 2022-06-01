// problem link->>>>>>>https://leetcode.com/problems/intersection-of-two-linked-lists/


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */


// first solution

class Solution {
public:
    int Listofsize(ListNode* node)
    {
        int len=0;
        while(node)
        {
            node=node->next;
            len++;
        }
        
        return len;
    }
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int sz1=Listofsize(headA);
        int sz2=Listofsize(headB);
    
        int diff=abs(sz1-sz2);
        
        if(sz1>sz2)
        {
            for(int i=0;i<diff;i++)
                headA=headA->next;
        }
        else
        {
            for(int i=0;i<diff;i++)
                headB=headB->next;
        }
        
        while(headA!=headB)
        {
            headA=headA->next;
            headB=headB->next;
        }
        
        return headA;
    }
};

//second solution

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *p1 = headA;
        ListNode *p2 = headB;
        
        if (p1 == NULL || p2 == NULL) 
            return NULL;

        while (p1 != NULL && p2 != NULL && p1 != p2) 
        {
            p1 = p1->next;
            p2 = p2->next;

            //
            // Any time they collide or reach end together without colliding 
            // then return any one of the pointers.
            //
            if (p1 == p2) return p1;

            //
            // If one of them reaches the end earlier then reuse it 
            // by moving it to the beginning of other list.
            // Once both of them go through reassigning, 
            // they will be equidistant from the collision point.
            //
            if (p1 == NULL) p1 = headB;
            if (p2 == NULL) p2 = headA;
        }
        
        return p1;
    }
};

// second solution

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* slow=head;
        ListNode* fast=head;
        
        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast) break;
        }
        
        if(fast==NULL || fast->next==NULL) return NULL;
        
        ListNode* curr1=head;
        ListNode* curr2=slow;
        while(curr1!=curr2){
            curr1=curr1->next;
            curr2=curr2->next;
        }
        return curr1;
    }
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* tailB=headB;
        while(tailB->next!=NULL)
            tailB=tailB->next;
        
        tailB->next=headB;
        ListNode* ans=detectCycle(headA);
        tailB->next=NULL;
        return ans;
    }
};