// problem link --> https://leetcode.com/problems/coin-change/

// memo + 1D DP
class Solution {
public:
    int helper(vector<int>& coins, int amount,vector<int> &dp)
    {
        if(amount<0) return INT_MAX;
        if(amount==0) return 0;
        
        if(dp[amount]!=-1) return dp[amount];
        
        int ans=INT_MAX-1;
        for(int i=0;i<coins.size();i++)
        {
            ans=min(ans,helper(coins,amount-coins[i],dp));
        }
        
        return dp[amount]=1+ans;
    }
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1,-1);
        int ans=helper(coins,amount,dp);
        return ans==INT_MAX?-1:ans;
    }
};

// memo + 2D DP
class Solution {
public:
    int helper(int idx,vector<int> &coins,int amount,vector<vector<int>> &dp)
    {
        if(amount==0) return 0;
        if(idx==coins.size()) return 1e6;
        
        if(dp[idx][amount]!=-1) return dp[idx][amount]; 
        
        int take=INT_MAX;
        if(coins[idx]<=amount)
            take=1+helper(idx,coins,amount-coins[idx],dp);
        
        int non_take=helper(idx+1,coins,amount,dp);
        
        return dp[idx][amount]=min(take,non_take);
    }
    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>> dp(coins.size()+1,vector<int>(amount+1,-1));
        int ans=helper(0,coins,amount,dp);
        return ans==1e6?-1:ans;
    }
};

// memo + 2D DP
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>> dp(coins.size()+1,vector<int>(amount+1,0));
        
        for(int i=0;i<=coins.size();i++)
        {
            for(int j=0;j<=amount;j++)
            {
                if(j==0)
                    dp[i][j]=0;
                else if(i==0)
                    dp[i][j]=1e8;
                else if(j>=coins[i-1])
                    dp[i][j]=min(1+dp[i][j-coins[i-1]],dp[i-1][j]);
                else
                    dp[i][j]=dp[i-1][j];                
            }
        }
        
        return (dp[coins.size()][amount]>1e5)? -1 : dp[coins.size()][amount];
    }
};

// tabulation + 1D DP
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1,INT_MAX-1);
        dp[0]=0;
        
        for(int i=1;i<=amount;i++)
        {
            for(int j=0;j<coins.size();j++)
            {
                if(i<coins[j]) continue;
                else{
                    dp[i]=min(dp[i],1+dp[i-coins[j]]);
                }
            }
        }
        
        return dp[amount]==INT_MAX-1?-1:dp[amount];
    }
};