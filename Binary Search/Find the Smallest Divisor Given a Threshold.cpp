// probelm link --> https://leetcode.com/problems/find-the-smallest-divisor-given-a-threshold/

class Solution {
public:
    int cost_function(vector<int> &nums,int k)
    {
        int ans=0;
        for(int i=0;i<nums.size();i++)
            ans+=ceil(1.0*nums[i]/k);
        return ans;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int low=1,high=*max_element(nums.begin(),nums.end());
        int ans=high;
        while(low<=high)
        {
            int midDivisor=low+(high-low)/2;
            if(cost_function(nums,midDivisor)<=threshold)
            {
                ans=midDivisor;
                high=midDivisor-1;
            }
            else
                low=midDivisor+1;
        }
        return ans;
    }
};