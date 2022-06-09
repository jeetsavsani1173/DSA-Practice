// problem link --> https://leetcode.com/problems/count-number-of-pairs-with-absolute-difference-k/


// brutefource
class Solution {
public:
    int countKDifference(vector<int>& nums, int k) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int ans=0;
        
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                if(nums[j]-nums[i]==k)
                    ans++;
            }
        }
        return ans;
    }
};

// optimize
class Solution {
public:
    int countKDifference(vector<int>& nums, int k) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        map<int,int> mp;
        int ans=0;
        for(int i=n-1;i>=0;i--)
        {
            ans+=mp[k+nums[i]];
            mp[nums[i]]++;
        }
        
        return ans;
    }
};