// problem link -->https://leetcode.com/problems/design-front-middle-back-queue/

class FrontMiddleBackQueue {
public:
    deque<int> left;
    deque<int> right;
    
    void balance()
    {
        if((left.size()+right.size())%2==0){
            while(left.size()>right.size()){
                right.push_front(left.back());
                left.pop_back();
            }
            while(left.size()<right.size()){
                left.push_back(right.front());
                right.pop_front();
            }
        }
        else{
            while(left.size()+1>right.size()){
                right.push_front(left.back());
                left.pop_back();
            }
            while(left.size()+1<right.size()){
                left.push_back(right.front());
                right.pop_front();
            }
        }
    }
    
    void pushFront(int val) {
        left.push_front(val);
        balance();
    }
    
    void pushMiddle(int val) {
        right.push_front(val);
        balance();
    }
    
    void pushBack(int val) {
        right.push_back(val);
        balance();
    }
    
    int popFront() {
        if(left.size()+right.size()==0) return -1;
        int val;
        if(left.size()==0){
            val=right.front();
            right.pop_front();
        }else{
            val=left.front();
            left.pop_front();
        }
        balance();
        return val;
    }
    
    int popMiddle() {
        if(left.size()+right.size()==0) return -1;
        int val;
        if((left.size()+right.size())%2==0){
            val=left.back();
            left.pop_back();
        }else{
            val=right.front();
            right.pop_front();
        }
        balance();
        return val;
    }
    
    int popBack() {
        if(left.size()+right.size()==0) return -1;
        int val=right.back();
        right.pop_back();
        balance();
        return val;
    }
};

/**
 * Your FrontMiddleBackQueue object will be instantiated and called as such:
 * FrontMiddleBackQueue* obj = new FrontMiddleBackQueue();
 * obj->pushFront(val);
 * obj->pushMiddle(val);
 * obj->pushBack(val);
 * int param_4 = obj->popFront();
 * int param_5 = obj->popMiddle();
 * int param_6 = obj->popBack();
 */