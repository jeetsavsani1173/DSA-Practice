// problem link --> https://practice.geeksforgeeks.org/problems/perfect-sum-problem5633/1

class Solution
{

public:
    int M = 1e9 + 7;
    long helper(int idx, int nums[], int n, int sum, vector<vector<long>> &dp)
    {
        // if(sum==0) return 1;
        if (idx == n && sum == 0)
            return 1;
        if (idx == n)
            return 0;
        // if(sum<0) return 0;

        if (dp[idx][sum] != -1)
            return dp[idx][sum];
        // Take
        long count = 0;
        // if(helper(idx+1,nums,n,sum-nums[idx],dp)>0)
        if (sum >= nums[idx])
            count += helper(idx + 1, nums, n, sum - nums[idx], dp);

        // Non_Take
        // if(helper(idx+1,nums,n,sum,dp)>0)
        count += helper(idx + 1, nums, n, sum, dp);

        return dp[idx][sum] = (count % M);
    }
    int perfectSum(int arr[], int n, int sum)
    {
        vector<vector<long>> dp(n + 1, vector<long>(sum + 1, -1));
        return helper(0, arr, n, sum, dp);
    }
};