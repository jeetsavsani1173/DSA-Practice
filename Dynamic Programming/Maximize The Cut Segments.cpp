problem link -->> https://practice.geeksforgeeks.org/problems/cutted-segments/0

// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
    int dp[10005];
    public:
    int func(int n,int a,int b,int c)
    {
        if(n==0) return 0;
        if(dp[n]!=-1)  return dp[n];
        
        int op1=INT_MIN,op2=INT_MIN,op3=INT_MIN;
        if(n>=a) op1=func(n-a,a,b,c);
        if(n>=b) op2=func(n-b,a,b,c);
        if(n>=c) op3=func(n-c,a,b,c);
        
        dp[n]=1+max(op1,max(op2,op3));
        return dp[n];
    }
    int maximizeTheCuts(int n, int x, int y, int z)
    {
        memset(dp,-1,sizeof(dp));
        
        int ans=func(n,x,y,z);
        if(ans<0)
            return 0;
        else
            return ans;
    }
};

// { Driver Code Starts.
int main() {
    
    //taking testcases
    int t;
    cin >> t;
    while(t--)
    {
        //taking length of line segment
        int n;
        cin >> n;
        
        //taking types of segments
        int x,y,z;
        cin>>x>>y>>z;
        Solution obj;
        //calling function maximizeTheCuts()
        cout<<obj.maximizeTheCuts(n,x,y,z)<<endl;

    }

	return 0;
}  // } Driver Code Ends