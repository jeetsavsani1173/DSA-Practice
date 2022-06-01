// problem link --> xhttps://www.lintcode.com/problem/533

class Solution {
public:
    /**
     * @param nums: an integer array
     * @param target: An integer
     * @return: the difference between the sum and the target
     */
    int twoSumClosest(vector<int> &nums, int target) {
        sort(nums.begin(),nums.end());
        int ans=INT_MAX;
        
        int left=0,right=nums.size()-1;
        while(left<right)
        {
            if(nums[left]+nums[right] < target){
                ans=min(ans,abs(target-nums[left]-nums[right]));
                left++;
            }else{
                ans=min(ans,abs(target-nums[left]-nums[right]));
                right--;   
            }
        }
        
        return ans;
    }
};