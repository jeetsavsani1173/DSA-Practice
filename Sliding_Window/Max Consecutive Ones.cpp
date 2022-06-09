// problem link --> https://leetcode.com/problems/max-consecutive-ones/

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int ans=0;
        int curr_cnt=0;
        
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==1)
                curr_cnt++;
            else
                curr_cnt=0;
            
            ans=max(ans,curr_cnt);
        }
        
        return ans;
    }
};