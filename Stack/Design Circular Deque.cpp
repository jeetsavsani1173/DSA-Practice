// problem link --> https://leetcode.com/problems/design-circular-deque/

class MyCircularDeque {
    vector<int> q;
    int front,rear,size;
public:
    MyCircularDeque(int k) {
        q=vector<int>(k,0);
        front=0,rear=0,size=0;
    }
    
    bool insertFront(int value) {
        if(size==q.size()) return false;
        
        q[(front-1+q.size())%q.size()]=value;
        front=(front-1+q.size())%q.size();
        size++;
        
        return true;
    }
    
    bool insertLast(int value) {
        if(size==q.size()) return false;
        
        q[rear]=value;
        rear=(rear+1)%q.size();
        size++;
        
        return true;
    }
    
    bool deleteFront() {
        if(size==0) return false;
        
        front=(front+1)%q.size();
        size--;
        
        return true;
    }
    
    bool deleteLast() {
        if(size==0) return false;
        rear=(+rear-1+q.size())%q.size();
        size--;
        
        return true;
    }
    
    int getFront() {
        return (size==0)?-1:q[front];
    }
    
    int getRear() {
        return (size==0)?-1:q[(q.size()+rear-1)%q.size()];
    }
    
    bool isEmpty() {
        return (size==0);
    }
    
    bool isFull() {
        return (size==q.size());
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */