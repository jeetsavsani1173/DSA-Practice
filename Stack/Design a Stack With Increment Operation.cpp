// problem link --> https://leetcode.com/problems/design-a-stack-with-increment-operation/

class CustomStack {
public:
    stack<int> st;
    int maxSize;
    CustomStack(int maxSize) {
        this->maxSize=maxSize;
    }
    
    void push(int x) {
        if(st.size()!=maxSize)
            st.push(x);
    }
    
    int pop() {
        if(st.size()==0) return -1;
        int val=st.top();
        st.pop();
        return val;
    }
    
    void increment(int k, int val) {
        stack<int> NewSt;
        while(!st.empty())
        {
            NewSt.push(st.top());
            st.pop();
        }
        
        if(k>NewSt.size())
            k=NewSt.size();
        
        while(!NewSt.empty())
        {
            int Nval=NewSt.top();
            NewSt.pop();
            if(k>0) {
                Nval+=val;
                k--;
            }
            
            st.push(Nval);
        }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */