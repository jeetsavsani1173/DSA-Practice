//problem link->https://leetcode.com/problems/coin-change-2/

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<int> dp(amount+1,0);
        
        dp[0]=1;
        
        for(int i=0;i<coins.size();i++)
            for(int j=coins[i];j<=amount;j++)
                dp[j]+=dp[j-coins[i]];
        
        return (dp[amount]==0)?0:dp[amount];
    }
};

// memo + 2D DP
class Solution {
public:
    int helper(int idx,vector<int> &coins,int amount,vector<vector<int>> &dp)
    {
        if(amount==0) return 1;
        if(idx==coins.size()) return 0;
        
        if(dp[idx][amount]!=-1) return dp[idx][amount]; 
        
        int take=0;
        if(coins[idx]<=amount)
            take=helper(idx,coins,amount-coins[idx],dp);
        
        int non_take=helper(idx+1,coins,amount,dp);
        
        return dp[idx][amount]=(take+non_take);
    }
    int change(int amount, vector<int>& coins) {
        vector<vector<int>> dp(coins.size()+1,vector<int>(amount+1,-1));
        return helper(0,coins,amount,dp);
    }
};