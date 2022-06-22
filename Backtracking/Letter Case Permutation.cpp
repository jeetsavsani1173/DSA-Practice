// problem link --> https://leetcode.com/problems/letter-case-permutation/

class Solution {
public:
    vector<string> ans;
    void helper(int idx,string str)
    {
        if(idx==str.size())
        {
            ans.push_back(str);
            return;
        }
        if(str[idx]>='0' && str[idx]<='9'){
            helper(idx+1,str);
            return;
        }
        string temp=str;
        if(str[idx]>='a' && str[idx]<='z'){
            str[idx]-=32;
        }else{
            str[idx]+=32;
        }
        helper(idx+1,str);
        helper(idx+1,temp);
    }
    vector<string> letterCasePermutation(string s) {
        helper(0,s);
        return ans;
    }
};