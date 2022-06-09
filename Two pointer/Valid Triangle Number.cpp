// problem link --> https://leetcode.com/problems/valid-triangle-number/

class Solution {
public:
    int TwoSumGreater(vector<int> nums,int left,int right,int target)
    {
        int ans=0;
        
        while(left<right)
        {
            if(nums[left]+nums[right]>target)
            {
                ans+=(right-left);
                right--;
            }
            else
                left++;
        }
        return ans;
    }
    int triangleNumber(vector<int>& nums) {
        int n=nums.size();
        if(2>=n) return 0;
        sort(nums.begin(),nums.end());
        int count=0;
        
        for(int i=2;i<n;i++)
        {
            count+=TwoSumGreater(nums,0,i-1,nums[i]);
        }
        return count;
    }
};