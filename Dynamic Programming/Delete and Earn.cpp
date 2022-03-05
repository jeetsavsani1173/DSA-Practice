// problem link -->  https://leetcode.com/problems/delete-and-earn/

class Solution {
public:
    int rec(int i,vector<int> &v,map<int,int> &mp,vector<int> &dp)
    {
        if(i>=(v.size()))
            return 0;
        
        if(dp[i]!=-1)
            return dp[i];
        
        int take;
        if((i+1)<v.size() && (v[i]==(v[i+1]-1)))
            take=mp[v[i]]*v[i]+rec(i+2,v,mp,dp);
        else
            take=mp[v[i]]*v[i]+rec(i+1,v,mp,dp);
        
        int nontake=rec(i+1,v,mp,dp);
        
        return dp[i]=max(take,nontake);
    }
    int deleteAndEarn(vector<int>& nums) {
        map<int,int> freq;
        for(int i=0;i<nums.size();i++)
            freq[nums[i]]++;
        
        sort(nums.begin(),nums.end());
        vector<int> v;
        v.push_back(nums[0]);
        for(int i=1;i<nums.size();i++)
            if(nums[i-1]!=nums[i])
                v.push_back(nums[i]);
        vector<int> dp(v.size()+1,-1);
        return rec(0,v,freq,dp);
    }
};