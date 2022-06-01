// problem link --> https://www.lintcode.com/problem/587

class Solution {
public:
    /**
     * @param nums: an array of integer
     * @param target: An integer
     * @return: An integer
     */
    int twoSum6(vector<int> &nums, int target) {
        sort(nums.begin(),nums.end());
        int ans=0;
        
        int left=0,right=nums.size()-1;
        while(left<right)
        {
            if(nums[left]+nums[right]==target){
                ans++;
                int temp=nums[left];
                while(nums[left]==temp) left++;
                temp=nums[right];
                while(nums[right]==temp) right--;
            }else if(nums[left]+nums[right] < target){
                left++;
            }else{
                right--;   
            }
        }
        
        return ans;
    }
};