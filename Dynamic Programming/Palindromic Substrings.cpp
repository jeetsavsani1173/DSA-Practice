// problem link --> https://leetcode.com/problems/palindromic-substrings/

// solution 1
class Solution {
public:
    int countSubstrings(string s) {
        int n=s.size();
        vector<vector<int>> dp(n,vector<int>(n,0));
        
        for(int i=0;i<n;i++)
        {
            for(int j=i;j<n;j++)
            {
                if(i==j)
                    dp[i][j]=1;
                else if(i==(j-1) && s[i]==s[j])
                    dp[i][j]=1;
                else if(i==(j-1))
                    dp[i][j]=0;
            }
        }
        
        for(int i=n-2;i>=0;i--)
        {
            for(int j=i+2;j<n;j++)
            {
                if(s[i]==s[j])
                    dp[i][j]=dp[i+1][j-1];
                else
                    dp[i][j]=0;
            }
        }
        int ans=0;
        for(int i=0;i<n;i++)
        {
            for(int j=i;j<n;j++)
            {
                ans+=dp[i][j];
            }
        }
        return ans;
    }
};

//solution 2

class Solution {
public:
    int countSubstrings(string s) {
        int n=s.size();
        vector<vector<int>> dp(n,vector<int>(n,0));
        int ans=0;
        
        for(int gape=0;gape<n;gape++)
        {
            int i=0,j=gape;
            while(j<n)
            {
                if(gape==0)
                    dp[i][j]=1;
                else if(gape==1)
                    dp[i][j]=(s[i]==s[j]);
                else
                {
                    if(s[i]==s[j])
                        dp[i][j]=dp[i+1][j-1];
                    else
                        dp[i][j]=0;
                }
                if(dp[i][j])
                    ans++;
                i++;
                j++;
            }
        }
        
        return ans;
    }
};