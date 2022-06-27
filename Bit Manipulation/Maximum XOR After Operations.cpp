// problem link --> https://leetcode.com/problems/maximum-xor-after-operations/

class Solution {
public:
    int maximumXOR(vector<int>& nums) {
        int ans=0;
        
        for(int bit=0;bit<30;bit++)
        {
            int count=0;
            for(int i=0;i<nums.size();i++)
                if(nums[i]&(1<<bit))
                    count++;
            
            if(count)
                ans+=(1<<bit);
        }
        return ans;
    }
};