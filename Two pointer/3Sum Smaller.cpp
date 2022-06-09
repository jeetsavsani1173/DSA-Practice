// problem link --> https://www.lintcode.com/problem/918

class Solution {
public:
    /**
     * @param nums:  an array of n integers
     * @param target: a target
     * @return: the number of index triplets satisfy the condition nums[i] + nums[j] + nums[k] < target
     */
    
    int TwoSumSmaller(vector<int> &nums,int left,int right,int target)
    {
        int ans=0;

        while(left<right)
        {
            if(nums[left]+nums[right]<target)
            {
                ans+=(right-left);
                left++;
            }
            else
                right--;
        }
        return ans;
    }
    int threeSumSmaller(vector<int> &nums, int target) {
        int n=nums.size();
        sort(nums.begin(),nums.end());

        int ans=0;

        for(int i=0;i<n-2;i++)
        {
            int New_target=target-nums[i];
            int left=i+1,right=n-1;

            ans+=TwoSumSmaller(nums,left,right,New_target);
        }

        return ans;
    }
};