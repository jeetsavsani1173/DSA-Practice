// problem link --> https://leetcode.com/problems/merge-k-sorted-lists/

// brute-fource solution
class Solution {
public:
    int Find_Min_Node_Index(vector<ListNode*>& lists)
    {
        int mn=INT_MAX;
        int idx=-1;
        
        for(int i=0;i<lists.size();i++)
        {
            if(lists[i]!=NULL && lists[i]->val<mn)
            {
                idx=i;
                mn=lists[i]->val;
            }
        }
        return idx;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size()==0)
            return NULL;
        
        ListNode* dummy=new ListNode(-1);
        ListNode* head=dummy;
        ListNode* tail=dummy;
        
        while(true){
            int minIdx=Find_Min_Node_Index(lists);
            if(minIdx==-1) break; // all list are empty..
            
            tail->next=lists[minIdx];
            lists[minIdx]=lists[minIdx]->next;
            tail=tail->next;
        }
        return dummy->next;
    }
};

// Using Divide-and-conqure
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* head1, ListNode* head2) {
        ListNode* head;
        ListNode* tail;
        ListNode* dummy=new ListNode(-1);
        head=tail=dummy;

        // merge to sorted LL..
        while(head1!=NULL && head2!=NULL){
            if(head1->val<head2->val){
                tail->next=head1;
                head1=head1->next;
                tail=tail->next;
            }
            else{
                tail->next=head2;
                head2=head2->next;
                tail=tail->next;
            }
        }

        if(head1!=NULL){
            tail->next=head1;
        }
        if(head2!=NULL){
            tail->next=head2;
        }

        return dummy->next;
    }
    ListNode* merge_list(vector<ListNode*>& lists,int l,int r)
    {
        if(l>r)
            return NULL;
        if(l==r)
            return lists[l];
        
        int mid=(l+r)/2;
        ListNode* first=merge_list(lists,l,mid);
        ListNode* second=merge_list(lists,mid+1,r);
        
        return mergeTwoLists(first,second);
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size()==0)
            return NULL;
        
        return merge_list(lists,0,lists.size()-1);
    }
};

// using Priority Queue
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size()==0)
            return NULL;
        
        ListNode* dummy=new ListNode(-1);
        ListNode* head=dummy;
        ListNode* tail=dummy;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > pq;
        for(int i=0;i<lists.size();i++){
            if(lists[i]!=NULL)
                pq.push({lists[i]->val,i});
        }
        while(!pq.empty()){
            int minIdx=pq.top().second;
            pq.pop();
            
            tail->next=lists[minIdx];
            lists[minIdx]=lists[minIdx]->next;
            tail=tail->next;
            if(lists[minIdx]!=NULL)
                pq.push({lists[minIdx]->val,minIdx});
        }
        return dummy->next;
    }
};