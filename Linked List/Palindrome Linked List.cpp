// problem link->>>>>>https://leetcode.com/problems/palindrome-linked-list/

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
public:
    bool isPalindrome(ListNode* head) {
        ListNode* curr=head;
        stack<int> st;
        while(head)
        {
            st.push(head->val);
            head=head->next;
        }
        
        while(curr)
        {
            if((curr->val)!=st.top())
                return false;
            if(!st.empty())
            st.pop();
            curr=curr->next;
        }
        
        return true;
    }
};

//second solution

class Solution {
public:// using recursion
    ListNode *temp;
    bool isPalindrome(ListNode* head) {
        temp=head;
        return check(head);
    }
    
    bool check(ListNode* head)
    {
        if(head==NULL) 
            return true;
        
        bool res=check(head->next);
        if(res==false) 
            return false;
        else 
        {
            if(temp->val!=head->val)
                return false;
        }
        
        temp=temp->next;
        
        return true;
    }
};


//third solution

class Solution {
public:// using recursion
    ListNode *temp;
    bool isPalindrome(ListNode* head) {
        temp=head;
        return check(head);
    }
    
    bool check(ListNode* p) {
        if (NULL == p) return true;
        bool isPal = check(p->next) & (temp->val == p->val);
        temp = temp->next;
        return isPal;
    }
};

//fourth solution

class Solution {
public:// using recursion
    bool isPalindrome(ListNode* head) {
        if(head==NULL||head->next==NULL)
            return true;
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast->next!=NULL&&fast->next->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        slow->next=reverseList(slow->next);
        slow=slow->next;
        while(slow!=NULL){
            if(head->val!=slow->val)
                return false;
            head=head->next;
            slow=slow->next;
        }
        return true;
    }
    ListNode* reverseList(ListNode* head) {
        ListNode* pre=NULL;
        ListNode* next=NULL;
        while(head!=NULL){
            next=head->next;
            head->next=pre;
            pre=head;
            head=next;
        }
        return pre;
    }
};