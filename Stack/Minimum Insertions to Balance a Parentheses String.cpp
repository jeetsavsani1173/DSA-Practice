// problem link --> https://leetcode.com/problems/minimum-insertions-to-balance-a-parentheses-string/

class Solution {
public:
    int minInsertions(string s) {
        int open=0,additions_ans=0;
        
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='(') open++;
            else{

                if(open>0) open--;
                else additions_ans++;
                
                if(i<s.size()-1 && s[i+1]==')')
                {
                    i++;
                }else{
                    additions_ans++;
                }
            }
        }
        
        return additions_ans+2*open;
    }
};