// problem link -> https://leetcode.com/problems/k-diff-pairs-in-an-array/

class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        set<pair<int,int>> stpr;
        sort(nums.begin(),nums.end());
        int n=nums.size();
 
        for(int i=0;i<n;i++)
            for(int j=i+1;j<n;j++)
                if((nums[j]-nums[i])==k)
                    stpr.insert({nums[i],nums[j]});
        
        return stpr.size();
    }
};


class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        set<int> uniqe_first_element;
        sort(nums.begin(),nums.end());
        int n=nums.size();
        for(int i=0;i<n-1;i++)
        {
           if(binary_search(nums.begin()+i+1,nums.end(),nums[i]+k))
               uniqe_first_element.insert(nums[i]);
        }
        
        return uniqe_first_element.size();
    }
};

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
