// problem link --> https://leetcode.com/problems/implement-queue-using-stacks/

class MyQueue {
public:
    stack<int> st;
    MyQueue() {
        
    }
    
    void push(int x) {
        st.push(x);
    }
    
    int pop() {
        stack<int> newSt;
        while(!st.empty())
        {
            int curr=st.top();
            st.pop();
            newSt.push(curr);
        }
        int res=newSt.top();
        newSt.pop();
        
        while(!newSt.empty())
        {
            int curr=newSt.top();
            newSt.pop();
            st.push(curr);
        }
        return res;
    }
    
    int peek() {
        stack<int> newSt;
        while(!st.empty())
        {
            int curr=st.top();
            st.pop();
            newSt.push(curr);
        }
        int res=newSt.top();
        
        while(!newSt.empty())
        {
            int curr=newSt.top();
            newSt.pop();
            st.push(curr);
        }
        return res;
    }
    
    bool empty() {
        return (st.size()==0);
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */