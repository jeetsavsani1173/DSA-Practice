// problem link --> https://leetcode.com/problems/letter-combinations-of-a-phone-number/

class Solution {
public:
    string codes[10]={" "," ","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    vector<string> function(string digits) {
        if(digits.size()==0)
        {
            vector<string> bres;
            bres.push_back("");
            return bres;
        }
        char ch=digits[0];
        string ros=digits.substr(1);
        
        vector<string> rres=function(ros);
        vector<string> ans;
        string codeforch=codes[ch-'0'];
        
        for(int i=0;i<codeforch.size();i++)
        {
            for(auto rstr:rres)
            {
                ans.push_back(codeforch[i]+rstr);
            }
        }
        if (ans.size()==0) ans.erase(ans.begin());
        
        return ans;
    }
    vector<string> letterCombinations(string digits) {
        if(digits.size()==0)
            return {};
        else
            return function(digits);
    }
};