// problem link --> https://www.lintcode.com/problem/859/

class MaxStack {
public:
    class ListNode{
        public:
        int val;
        ListNode* prev;
        ListNode* next;

        ListNode(int value)
        {
            val=value;
            next = NULL;
            prev = NULL;
        }
        ListNode(int value,ListNode* p,ListNode* n)
        {
            val=value;
            next = n;
            prev = p;
        }
    };
    map<int,vector<ListNode*>> mp;
    ListNode *head,*tail;
    MaxStack() {
        head=new ListNode(-1);
        tail=new ListNode(-1);
        head->next=tail;
        tail->prev=head;
    }

    void push(int number) {
        // insert at last..
        ListNode* curr=new ListNode(number,tail->prev,tail);
        tail->prev->next=curr;
        tail->prev=curr;

        vector<ListNode*> arr=mp[number];
        arr.push_back(curr);
        mp[number]=arr;
    }

    int pop() {
        ListNode* curr=tail->prev;
        curr->prev->next=curr->next;
        curr->next->prev=curr->prev;

        vector<ListNode*> arr=mp[curr->val];
        arr.pop_back();
        if(arr.size()==0) mp.erase(curr->val);
        else mp[curr->val]=arr;

        return curr->val;
    }

    /*
     * @return: An integer
     */
    int top() {
        return tail->prev->val;
    }
    
    /*
     * @return: An integer
     */
    int peekMax() {
        auto it=--mp.end();
        return it->first;
    }
    
    /*
     * @return: An integer
     */
    int popMax() {
        auto it=--mp.end();
        int maxVal=it->first;
        vector<ListNode*> arr=mp[maxVal];
        ListNode* curr=arr[arr.size()-1];

        curr->prev->next=curr->next;
        curr->next->prev=curr->prev;

        arr.pop_back();
        if(arr.size()==0) mp.erase(curr->val);
        else mp[curr->val]=arr;

        return curr->val;
    }
};