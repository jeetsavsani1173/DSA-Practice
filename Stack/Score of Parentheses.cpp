// problem link --> https://leetcode.com/problems/score-of-parentheses/

class Solution {
public:
    int scoreOfParentheses(string s) {
        stack<int> stk;
        
        for(auto &it:s)
        {
            if(it=='(') stk.push(-1);
            else{
                if(stk.top()==-1){
                    stk.pop();
                    stk.push(1);// push score of "()"->1
                }else{
                    int count=0;
                    while(stk.top()!=-1)
                    {
                        count+=stk.top();
                        stk.pop();
                    }
                    stk.pop(); // popping opening bracket..
                    stk.push(2*count); // "( ()() )" -> 2*(1+1) -> 4
                }
            }
        }
        
        int ans=0;
        while(!stk.empty())
        {
            ans+=stk.top();
            stk.pop();
        }
        return ans;
    }
};