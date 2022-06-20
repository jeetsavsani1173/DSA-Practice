// problem link --> https://www.lintcode.com/problem/779/

class Solution {
public:
    vector<string> ans;
    void helper(int idx,string &word,string output,int count)
    {
        if(idx==word.size())
        {
            if(count!=0) output+=to_string(count);
            ans.push_back(output);
            return;
        } 
        
        // for Take..
        string temp=output;
        if(count!=0) 
            temp+=to_string(count);
        temp+=word[idx];
        helper(idx+1,word,temp,0);

        // for Non-Take
        helper(idx+1,word,output,count+1);
    }
    vector<string> generateAbbreviations(string &word) {
        string output;
        helper(0,word,output,0);
        return ans;
    }
};