// problem  link -->https://www.codingninjas.com/codestudio/problems/sort-a-stack_985275

void addAtProperPosition(stack<int> &st,int val,int prev)
{
    if(st.size()==0){
        if(val<=prev)
            st.push(val);
        return;
    }
    int currVal=st.top();
    st.pop();
    addAtProperPosition(st,val,currVal);
    st.push(currVal);
    if(val<=prev && val>currVal)
        st.push(val);
}
void sortStack(stack<int> &stack)
{
	if(stack.size()==0) return;
    int val=stack.top();
    stack.pop();
    sortStack(stack);
    addAtProperPosition(stack,val,1e9+5);
}