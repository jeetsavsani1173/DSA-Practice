// problem link --> https://www.lintcode.com/problem/610

class Solution {
public:
    /**
     * @param nums: an array of Integer
     * @param target: an integer
     * @return: [num1, num2] (index1 < index2)
     */
    vector<int> twoSum7(vector<int> &nums, int target) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        if(n<2) return {};
        int p1=0,p2=1;
        while(p1<n && p2<n)
        {
            if(p1==p2){
                if(target<0) p1++;
                else p2++;
                continue;
            }
            int diff=nums[p2]-nums[p1];
            if(diff==target){
                return {min(nums[p1],nums[p2]),max(nums[p1],nums[p2])};
            }else if(diff<target){
                p2++;
            }else{
                p1++;
            }
        }
        return {};
    }
};