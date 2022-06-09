// problem link --> https://leetcode.com/problems/3sum-closest/

class Solution {
public:
    int TwoSumClosest(vector<int> &nums,int left,int right, int target) {
        int temp=INT_MAX;
        int ans=INT_MAX;
        while(left<right)
        {
            int sum=nums[left]+nums[right];
            if(sum == target)
                return target;
            else if(sum < target){
                if(target-sum < temp){
                    temp=target-sum;
                    ans=sum;
                }
                left++;
            }else{
                if(sum-target < temp){
                    temp=sum-target;
                    ans=sum;
                }
                right--;   
            }
        }
        return ans;
    }
    int threeSumClosest(vector<int>& nums, int target) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        
        int ans=0;
        int temp=INT_MAX;
        
        for(int i=0;i<n-2;i++)
        {
            int curr=TwoSumClosest(nums,i+1,n-1,target-nums[i])+nums[i];
            
            if(abs(curr-target) < temp)
            {
                temp=abs(curr-target);
                ans=curr;
            }
        }
        
        return ans;
    }
};