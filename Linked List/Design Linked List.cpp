// problem link --> https://leetcode.com/problems/design-linked-list/

// struct ListNode {
//         int val;
//         ListNode *next;
//         ListNode() : val(0), next(nullptr) {}
//         ListNode(int x) : val(x), next(nullptr) {}
//         ListNode(int x, ListNode *next) : val(x), next(next) {}
//  }
class MyLinkedList {
    ListNode *head;
    int size;
public:
    MyLinkedList() {
        head=NULL;
        size=0;
    }
    
    int get(int index) {
        if(index>=(size))
            return -1;
        int cnt=0;
        ListNode *temp=head;
        if(cnt==index)
                return temp->val;
        while(cnt<index)
        {
            temp=temp->next;
            cnt++;
            if(cnt==index)
                return temp->val;
        }
        return -1;
    }
    
    void addAtHead(int val) {
        size++;
        ListNode* node=new ListNode(val);
        node->next=head;
        head=node;
    }
    
    void addAtTail(int val) {
        if(head==NULL){
            addAtHead(val);
            return;
        }
        ListNode* temp=head;
        while(temp->next)
            temp=temp->next;
        
        ListNode* node=new ListNode(val);
        temp->next=node;
        size++;
    }
    
    void addAtIndex(int index, int val) {
        if(index==0){
            addAtHead(val);
            return;
        }
        if(index>size)
            return;
        if(index==size){
            addAtTail(val);
            return;
        }
        int cnt=index-1;
        ListNode* indexNode=head;
        while(cnt--)
            indexNode=indexNode->next;
        
        ListNode* node=new ListNode(val);
        node->next=indexNode->next;
        indexNode->next=node;
        size++;
    }
    
    void deleteAtIndex(int index) {
        if(index>=size)
            return;
        if(index==0){
            head=head->next;
            size--;
            return;
        }
        
        int cnt=index-1;
        ListNode* indexNode=head;
        while(cnt--)
            indexNode=indexNode->next;
        
        indexNode->next=indexNode->next->next;
        size--;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */