// problem link --> https://www.lintcode.com/problem/609

class Solution {
public:
    /**
     * @param nums: an array of integer
     * @param target: an integer
     * @return: an integer
     */
    int twoSum5(vector<int> &nums, int target) {
        sort(nums.begin(),nums.end());
        int left=0,right=nums.size()-1;
        int ans=0;
        while(left<right){
            if(nums[left]+nums[right] > target){
                right--;
            }else{
                ans+=(right-left);
                left++;
            }
        }
        return ans;
    }
};