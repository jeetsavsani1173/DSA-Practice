// problem link --> https://www.codingninjas.com/codestudio/problems/reverse-stack-using-recursion_631875

void insertAtBottom(stack<int> &st,int num)
{
    if(st.size()==0) {
        st.push(num);
        return;
    }
    int num1=st.top();
    st.pop();
    insertAtBottom(st,num);
    st.push(num1);
}
void reverseStack(stack<int> &stack) {
    if(stack.size()==0) return;
    int num=stack.top();
    stack.pop();
    reverseStack(stack);
    insertAtBottom(stack,num);
}