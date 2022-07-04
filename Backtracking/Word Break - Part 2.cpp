// problem link -->https://practice.geeksforgeeks.org/problems/word-break-part-23249/1#

class Solution{
public:
    vector<string> ans;
    void helper(int curr_idx,vector<string> &dist,int n,string &s,string temp)
    {
        if(curr_idx>=s.size()){
            ans.push_back(temp);
            return;
        }
        
        for(auto it:dist)
        {
            string first_str=it;
            string second_str=s.substr(curr_idx,first_str.size());
            if(first_str==second_str){
                string ans;
                if(temp.size()!=0) ans=temp+" "+first_str;
                else ans=first_str;
                helper(curr_idx+first_str.size(),dist,n,s,ans);
            }
        }
        return;
    }
    vector<string> wordBreak(int n, vector<string>& dict, string s)
    {
        string temp="";
        helper(0,dict,n,s,temp);
        return ans;
    }
};