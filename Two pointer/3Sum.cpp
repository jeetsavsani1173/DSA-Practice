// problem link --> https://leetcode.com/problems/3sum/

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        if(n<=2) return ans;
        
        for(int i=0;i<n;i++)
        {
            if(i>0 && nums[i]==nums[i-1])
                continue;
            
            int target=-1*nums[i];
            //Two-pointer for unique pair..
            int left=i+1,right=n-1;
            while(left<right)
            {
                if(nums[left]+nums[right]==target)
                {
                    ans.push_back({nums[i],nums[left],nums[right]});
                    int temp=nums[left];// remove of duplicate
                    while(left<n && nums[left]==temp)
                        left++;
                }
                else if(nums[left]+nums[right]>target)
                    right--;
                else
                    left++;
            }
        }
        
        return ans;
    }
};