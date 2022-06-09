// problem link --> https://leetcode.com/problems/k-diff-pairs-in-an-array/

// first solution using hashing
class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        int n=nums.size();
        for(int i=0;i<n;i++)
            mp[nums[i]]++;
        
        int ans=0;
        
        for(auto it:mp)
        {
            if(k==0)
            {
                if(it.second>=2)
                    ans++;
            }
            else
            {
                if(mp.find(it.first+k)!=mp.end())
                    ans++;
            }
        }
        
        return ans;
    }
};

//second solution

class Solution {
public:
    int diffPair(vector<int> &nums,int target)
    {
        int n=nums.size();
        int left=0,right=1,count=0;
        while(left < n && right < n){
            if(left>0 && nums[left]==nums[left-1]){
                left++;
                continue;
            }
            if(left==right){
                right++;
                continue;
            }
            int diff=nums[right]-nums[left];
            
            if(diff==target){
                count++,left++;
            }else if(diff<target){
                right++;
            }else{
                left++;
            }
        }
        return count;
    }
    int findPairs(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        return diffPair(nums,k);
    }
};