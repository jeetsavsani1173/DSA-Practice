// problem link --> https://leetcode.com/problems/two-sum/

// TC : O(N^2) SC : O(1)
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        for(int i=0;i<nums.size()-1;i++)
        {
            for(int j=i+1;j<nums.size();j++)
            {
                if(nums[i]+nums[j]==target)
                {
                    ans.push_back(i);
                    ans.push_back(j);
                    break;
                }
            }
        }
        
        return ans;
    }
};

class Solution {
public: // Tc : O(N) Sc : O(N) using HashMap
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int> mp;
        
        for(int i=0;i<nums.size();i++)
        {
            if(mp[target-nums[i]]==0){
                mp[nums[i]]=i+1;
            }
            else{
                return {mp[target-nums[i]]-1,i};
            }
        }
        return {};
    }
};

class Solution {
public: // Tc : O(NlogN) Sc : O(1) using sorting + two pointer
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<pair<int,int>> vpr;
        for(int i=0;i<nums.size();i++)
            vpr.push_back({nums[i],i});
        
        sort(vpr.begin(),vpr.end());
        
        int i=0,j=nums.size()-1;
        
        while(i<j)
        {
            if(vpr[i].first+vpr[j].first==target)
                return {vpr[i].second,vpr[j].second};
            else if(vpr[i].first+vpr[j].first > target)
                j--;
            else
                i++;
        }
        return {};
    }
};