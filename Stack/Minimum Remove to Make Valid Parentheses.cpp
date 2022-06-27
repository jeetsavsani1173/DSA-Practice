// problem link --> https://leetcode.com/problems/minimum-remove-to-make-valid-parentheses/

class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<int> stk;
        
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='(')
                stk.push(i);
            else if(s[i]==')')
            {
                if(stk.size()==0) stk.push(i);
                else if(s[stk.top()]=='(') stk.pop();
                else stk.push(i);
            }
        }
        while(!stk.empty())
        {
            s[stk.top()]='0';
            stk.pop();
        }
        
        string ans;
        for(auto it:s)
            if(it!='0')
                ans.push_back(it);
        
        return ans;
    }
};