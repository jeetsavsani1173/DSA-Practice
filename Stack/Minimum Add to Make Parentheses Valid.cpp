// problem link --> https://leetcode.com/problems/minimum-add-to-make-parentheses-valid/

class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char> stk;
        
        for(auto &it:s)
        {
            if(it=='(') stk.push('(');
            else if(stk.empty()==false && stk.top()=='(') stk.pop();
            else stk.push(it);
        }
        return stk.size();
    }
};