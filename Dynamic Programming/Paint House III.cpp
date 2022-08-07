// problem link --> https://leetcode.com/problems/paint-house-iii/

class Solution {
public:
    int dp[101][21][101];
    int helper(int idx,int prev_col,int t_neighbor,vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target)
    {
        if(t_neighbor>target) return INT_MAX/2;
        if(idx==m){
            if(t_neighbor==target) return 0;
            else return INT_MAX/2;
        }
        if(dp[idx][prev_col][t_neighbor]!=-1) return dp[idx][prev_col][t_neighbor];
        
        int ans=INT_MAX/2;
        if(houses[idx]==0){
            for(int color=1;color<=n;color++)
            {
                ans=min(ans,cost[idx][color-1]+helper(idx+1,color,(color==prev_col)?t_neighbor:(t_neighbor+1),houses,cost,m,n,target));
            }
        }else{
            ans=min(ans,helper(idx+1,houses[idx],(houses[idx]==prev_col)?t_neighbor:(t_neighbor+1),houses,cost,m,n,target));
        }
        
        return dp[idx][prev_col][t_neighbor]=ans;
    }
    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
        memset(dp,-1,sizeof(dp));
        int ans=helper(0,0,0,houses,cost,m,n,target);
        return (ans==INT_MAX/2)?-1:ans;
    }
};