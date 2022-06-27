// problem link --> https://leetcode.com/problems/design-circular-queue/

class MyCircularQueue {
    vector<int> q;
    int front,rear,size;
public:
    MyCircularQueue(int k) {
        q=vector<int>(k,0);
        front=0,rear=0,size=0;
    }
    
    bool enQueue(int value) {
        if(size==q.size()) return false;
        
        q[rear]=value;
        rear=(rear+1)%q.size();
        size++;
        
        return true;
    }
    
    bool deQueue() {
        if(size==0) return false;
        
        front=(front+1)%q.size();
        size--;
        
        return true;
    }
    
    int Front() {
        return (size==0)?-1:q[front];
    }
    
    int Rear() {
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
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */