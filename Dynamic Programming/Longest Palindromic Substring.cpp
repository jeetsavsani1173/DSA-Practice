// problem link --> https://leetcode.com/problems/longest-palindromic-substring/

class Solution {
public:
    string longestPalindrome(string s) {
        if(s.size()==0) return "";
        int n=s.size();
        vector<vector<bool>> dp(n,vector<bool>(n,false));
        
        int maxLen=1,startIdx=0;
        
        for(int gape=0;gape<n;gape++)
        {
            for(int i=0,j=gape;j<n;j++,i++)
            {
                if(gape==0){
                    dp[i][j]=1;
                }else if(gape==1){
                    if(s[i]==s[j])
                    {
                        dp[i][j]=1;
                        maxLen=2;
                        startIdx=i;
                    }
                }else{
                    if(s[i]==s[j] && dp[i+1][j-1])
                    {
                        dp[i][j]=true;
                        if(gape+1 > maxLen)
                        {
                            maxLen=gape+1;
                            startIdx=i;
                        }
                    }
                }
            }
        }
        return s.substr(startIdx, maxLen);
    }
};