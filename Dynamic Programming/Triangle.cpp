// problem link --> https://leetcode.com/problems/triangle/

class Solution {
public:
    int helper(int row,int col,vector<vector<int>>& triangle,vector<vector<int>> &dp)
    {
        if(row==triangle.size()-1)
        {
            return triangle[row][col];
        }
        if(dp[row][col]!=-1) return dp[row][col];
        int left=helper(row+1,col,triangle,dp);
        int right=helper(row+1,col+1,triangle,dp);
        
        return dp[row][col] = triangle[row][col]+min(left,right);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<vector<int>> dp(triangle.size(),vector<int>(triangle[triangle.size()-1].size(),-1));
        return helper(0,0,triangle,dp);
    }
};