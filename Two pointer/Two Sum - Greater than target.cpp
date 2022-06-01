// problem link --> https://www.lintcode.com/problem/443

class Solution {
public:
    /**
     * @param nums: an array of integer
     * @param target: An integer
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
    int twoSum2(vector<int> &nums, int target) {
        int n=nums.size();
        return n*(n-1)/2 - twoSum5(nums,target);
    }
};

// second solution
class Solution {
public:
    /**
     * @param nums: an array of integer
     * @param target: An integer
     * @return: an integer
     */
    int twoSum2(vector<int> &nums, int target) {
        sort(nums.begin(),nums.end());
        int left=0,right=nums.size()-1;
        int ans=0;
        while(left<right){
            if(nums[left]+nums[right] > target){
                ans+=(right-left);
                right--;
            }else{
                left++;
            }
        }
        return ans;
    }
};