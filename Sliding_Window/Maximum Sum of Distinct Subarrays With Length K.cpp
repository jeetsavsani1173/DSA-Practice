// problem link --> https://leetcode.com/contest/weekly-contest-318/problems/maximum-sum-of-distinct-subarrays-with-length-k/

class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        map<long long,long long> mp;
        long long sum=0;
        for(int i=0;i<k;i++){
            mp[nums[i]]++;
            sum+=nums[i];
        }
        
        long long ans=0;
        if(mp.size()==k){
            ans=sum;
        }
        
        for(int i=k;i<nums.size();i++)
        {
            if(mp[nums[i-k]]==1){
                mp.erase(nums[i-k]);
            }else{
                mp[nums[i-k]]--;
            }
            sum-=nums[i-k];
            mp[nums[i]]++;
            sum+=nums[i];
            if(mp.size()==k)
            {
                ans=max(ans,sum);
            }
        }
        return ans;
    }
};