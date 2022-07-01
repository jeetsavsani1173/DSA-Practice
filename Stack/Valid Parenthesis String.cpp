// problem link -->     https://leetcode.com/problems/valid-parenthesis-string/

class Solution {
public:
    bool checkValidString(string s) {
        stack<int> open,star;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='(')
                open.push(i);
            else if(s[i]=='*')
                star.push(i);
            else // Case 3 : for  ')'
            {
                if(!open.empty())
                    open.pop();
                else if(!star.empty())
                    star.pop();
                else
                    return false;
            }
        }
        
        // now process leftover opening parenthesis
        while(!open.empty())
        {
            if(star.empty())
                return false;
            else if(open.top()<star.top())
            {
                open.pop();
                star.pop();
            }
            else // open.top()>star.top()
                return false;
        }
        return true;
    }
};

// second code of same apporoach..
class Solution {
public:
    bool checkValidString(string s) {
        stack<int> open,star;
        
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='(') open.push(i);
            else if(s[i]=='*') star.push(i);
            else{
                if(open.size()>0) open.pop();
                else if(star.size()>0) star.pop();// convert * to "("
                else return false;
            }
        }
        
        // extra opening bracket..
        if(open.size()>star.size()) return false;
        
        // check for replace * to ")"
        while(!open.empty())
        {
            if(open.top()>star.top()) return false;
            open.pop();
            star.pop();
        }
        
        return true;
    }
};