// problem link --> https://leetcode.com/problems/implement-stack-using-queues/

class MyStack {
    queue<int> q;
public:
    MyStack() {
        
    }
    
    void push(int x) {
        q.push(x);
    }
    
    int pop() {
        int size=q.size();
        int res;
        for(int i=0;i<size-1;i++)
        {
            int curr=q.front();
            q.pop();
            q.push(curr);
        }
        res=q.front();
        q.pop();
        return res;
    }
    
    int top() {
        int size=q.size();
        int res;
        for(int i=0;i<size;i++)
        {
            int curr=q.front();
            q.pop();
            q.push(curr);
            if(i==(size-1))
                res=curr;
        }
        return res;
    }
    
    bool empty() {
         return (q.size()==0);
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */