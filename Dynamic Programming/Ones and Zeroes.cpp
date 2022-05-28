// problem link --> https://leetcode.com/submissions/detail/705169019/

class Solution {
public:
    int dp[605][101][101];
    int count_zeroes(string s)
    {
        int cnt=0;
        for(auto it:s)
            cnt+=(it=='0');
        return cnt;
    }
    int rec(vector<string> &strs,int idx,int m,int n)
    {
        if(idx==strs.size() || m+n==0)
            return 0;
        if(dp[idx][m][n]!=(-1))
            return dp[idx][m][n];
        
        int ans1=0,ans2=0;
        int cnt0=count_zeroes(strs[idx]);
        int cnt1=strs[idx].size()-cnt0;
        
        if(cnt0<=m && cnt1<=n)// take
            ans1=1+rec(strs,idx+1,m-cnt0,n-cnt1);
        
        // Non-take
        ans2=rec(strs,idx+1,m,n);
            
        return dp[idx][m][n]=max(ans1,ans2);
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        memset(dp,-1,sizeof(dp));
        int ans=rec(strs,0,m,n);
        return ans;
    }
};