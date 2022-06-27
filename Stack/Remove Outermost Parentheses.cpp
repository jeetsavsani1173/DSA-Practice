// problem link --> https://leetcode.com/problems/remove-outermost-parentheses/

class Solution {
public:
    string removeOuterParentheses(string s) {
        stack<int> stk;
        
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='(') stk.push(i);
            else{
                if(stk.size()==1){
                    s[stk.top()]='0';
                    s[i]='0';
                }
                stk.pop();
            }
        }
        
        string ans;
        for(auto &it:s)
            if(it!='0')
                ans.push_back(it);
        
        return ans;
    }
};

// without extra space...
class Solution {
public:
    string removeOuterParentheses(string s) {
        int count=0;
        string ans;
        for(auto &it:s)
        {
            if(it=='('){
                if(count) ans.push_back(it);
                count++;
            }else{
                count--;
                if(count) ans.push_back(it);
            }
        }
        return ans;
    }
};