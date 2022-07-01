// problem link --> https://leetcode.com/problems/longest-valid-parentheses/

class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> st;
        st.push(-1);
        int ans=0;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='(')
                st.push(i);
            else
            {
                st.pop();
                if(st.empty())
                    st.push(i);
                else{
                    int len=i-st.top();
                    ans=max(ans,len);
                }
            }
        }
        return ans;
    }
};

// second solution
class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> stk;
        
        int ans=0;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='(') stk.push(i);
            else{
                if(stk.size()==0 || s[stk.top()]==')') stk.push(i);
                else stk.pop();
            }
            int lastUnBalIdx=(stk.size()==0)?-1:stk.top();
            ans=max(ans,i-lastUnBalIdx);
        }
        
        return ans;
    }
};