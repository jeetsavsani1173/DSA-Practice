// problem link -->  https://leetcode.com/problems/split-array-largest-sum/
// Quetion on Answer on Bianry Search
class Solution {
public:
    bool isPossible(vector<int> &nums,int n,int maxSum,int m)
    {
        int No_Of_subarray=1;
        int currSum=0;
        
        for(int i=0;i<n;i++)
        {
            currSum+=nums[i];
            if(currSum>maxSum)
            {
                No_Of_subarray++;
                currSum=nums[i];
            }
            if(No_Of_subarray>m)
                return false;
        }
        
        return true;
    }
    int maxOfArray(vector<int> &nums,int n)
    {
        int mx=0;
        for(int i=0;i<n;i++)
            mx=max(mx,nums[i]);
        return mx;
    }
    int SumOfArray(vector<int> &nums,int n)
    {
        int sum=0;
        for(int i=0;i<n;i++)
            sum+=nums[i];
        return sum;
    }
    int splitArray(vector<int>& nums, int m) {
        int low=maxOfArray(nums,nums.size());
        int high=SumOfArray(nums,nums.size());
        
        int ans=high;
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            
            if(isPossible(nums,nums.size(),mid,m))
            {
                ans=mid;
                high=mid-1;
            }
            else
                low=mid+1;
        }
        return ans;
    }
};