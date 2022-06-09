// problem link --> https://practice.geeksforgeeks.org/problems/maximum-sum-of-subarray-less-than-or-equal-to-x4033/1

int findMaxSubarraySum(long long nums[], int n, long long target)
	{
	    long long left=0,CurrSum=0,ans=0;
	    
	    for(int right=0;right<n;right++)
        {
            CurrSum+=nums[right];
            
            while(CurrSum>target)
            {
                CurrSum-=nums[left];
                left++;
            }
            ans=max(ans,CurrSum);
        }
        
        return (int)ans;
	}  