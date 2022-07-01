// problem link --> https://leetcode.com/problems/reverse-substrings-between-each-pair-of-parentheses/

class Solution {
public:
    string reverseParentheses(string s) {
        stack<char> stk;
        
        for(auto &it:s)
        {
            if(it!=')') stk.push(it);
            else{
                string temp;
                while(stk.top()!='(')
                {
                    temp.push_back(stk.top());
                    stk.pop();
                }
                
                stk.pop(); // remove opening brace..
                for(auto &it:temp)
                    stk.push(it);
            }
        }
        
        string ans;
        while(!stk.empty()){
            ans+=stk.top();
            stk.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};