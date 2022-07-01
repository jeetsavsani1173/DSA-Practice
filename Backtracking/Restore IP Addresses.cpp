// problem link --> https://leetcode.com/problems/restore-ip-addresses/

class Solution {
public:
    vector<string> ans;
    string check(string s,vector<bool> &spot)
    {
        string IP;
        for(int i=0;i<s.size();i++)
        {
            if(spot[i]==true){
                IP.push_back('.');
            }
            IP.push_back(s[i]);
        }
        s=IP;
        // cout<<IP<<endl;
        string ans;
        int count=0,curr_num=0;
        for(int i=0;i<s.size();i++)
        {
            if(curr_num>255) return "";
            if(s[i]=='.'){
                string temp=to_string(curr_num);
                if(temp.size()!=count) return "";
                else{
                    ans+=temp;
                    ans.push_back('.');
                }
                count=0;
                curr_num=0;
            }else{
                curr_num=curr_num*10+((int)s[i]-'0');
                count++;
            }
        }
        if(curr_num>255) return "";
        string temp=to_string(curr_num);
        if(temp.size()!=count) return "";
        else{
            ans+=temp;
        }
        return ans;
    }
    void helper(int idx,string &s,int k,vector<bool> &spot)
    {
        if(k==0)
        {
            string temp=check(s,spot);
            if(temp.size()!=0) ans.push_back(temp);
            return;
        }else if(idx==spot.size()) return;
        
        spot[idx]=true;
        helper(idx+1,s,k-1,spot);
        spot[idx]=false;
        
        helper(idx+1,s,k,spot);
    }
    vector<string> restoreIpAddresses(string s) {
        vector<bool> spot(s.size(),false);
        helper(1,s,3,spot);
        return ans;
    }
};