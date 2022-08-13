// problem link --> https://leetcode.com/problems/decode-ways/'

class Solution {
public:
    int helper(int idx,int n,string &s,vector<int> &dp)
    {
        if(idx==n+1) return 1;
        // for only 1 digit
        int ans=0;
        if(dp[idx]!=-1) return dp[idx];
        if(s[idx]!='0')
            ans=helper(idx+1,n,s,dp);
        
        if(idx+1<=n){
            string temp="";
            temp+=s[idx];
            temp+=s[idx+1];
            int num=stoi(temp);
            if(s[idx]!='0' && 0<num && num<27)
                ans+=helper(idx+2,n,s,dp);
        }
        return dp[idx]=ans;
    }
    int numDecodings(string s) {
        vector<int> dp(s.size()+1,-1);
        return helper(0,s.size()-1,s,dp);
    }
};