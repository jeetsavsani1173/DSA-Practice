// problem link --> https://leetcode.com/problems/4sum/

// first solution
class Solution {
public:
    vector<pair<int,int>> TwoSum(vector<int> &nums,int left,int right,int target)
    {
        vector<pair<int,int>> ans;
        while(left<right)
        {
            if(nums[left]+nums[right]==target)
            {
                ans.push_back({nums[left],nums[right]});
                int temp=nums[left];
                while(left<nums.size() && temp==nums[left])
                    left++;
            }
            else if(nums[left]+nums[right]<target)
                left++;
            else
                right--;
        }
        return ans;
    }
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        vector<vector<int>> ans;
        if(n<=3) return ans;
        for(int i=0;i<n-3;i++)
        {
            if(i>0 && nums[i]==nums[i-1]) continue;
            
            for(int j=i+1;j<n-2;j++)
            {
                if(j>i+1 && nums[j]==nums[j-1]) continue;
                int left=j+1,right=n-1;
                vector<pair<int,int>>temp=TwoSum(nums,left,right,target-nums[i]-nums[j]);
                for(auto it:temp)
                    ans.push_back({nums[i],nums[j],it.first,it.second});
            }
        }
        
        return ans;
    }
};

//second solution
class Solution {
public:
    vector<vector<int>> TwoSum(vector<int> &nums,int left,int target)
    {
        vector<vector<int>> ans;
        int right=nums.size()-1;
        while(left<right)
        {
            if(nums[left]+nums[right]==target)
            {
                ans.push_back({nums[left],nums[right]});
                int temp=nums[left];
                while(left<nums.size() && temp==nums[left]) left++;
            }
            else if(nums[left]+nums[right] < target)
                left++;
            else
                right--;
        }
        return ans;
    }
    vector<vector<int>> kSum(vector<int> &nums,int start,int target,int k)
    {
        if(k>nums.size())
        {
            vector<vector<int>> bres;
            return bres;
        }
        if(k==2)
            return TwoSum(nums,start,target);
        vector<vector<int>> res;
        
        for(int i=start;i<=(nums.size()-k);i++)
        {
            if(i>start && nums[i]==nums[i-1])
                continue;
            vector<vector<int>> subRes=kSum(nums,i+1,target-nums[i],k-1);
            for(vector<int> it:subRes)
            {
                vector<int> temp=it;
                temp.push_back(nums[i]);
                res.push_back(temp);
            }
        }
        return res;
    }
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        return kSum(nums,0,target,4);
    }
};