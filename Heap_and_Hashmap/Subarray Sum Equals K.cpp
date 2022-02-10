// probelm link --> https://leetcode.com/problems/subarray-sum-equals-k/


class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int ans=0;
        int n=nums.size();

        int currsum=0;
        map<int,int> mp;
        for(int i=0;i<n;i++)
        {
            currsum+=nums[i];
            if(currsum==k)
                ans++;
            if(mp.find(currsum-k)!=mp.end())
                ans+=mp[currsum-k];
            mp[currsum]++;
        }
        
        return ans;
    }
};