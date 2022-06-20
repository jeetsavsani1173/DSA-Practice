// problem link --> https://leetcode.com/problems/set-mismatch/

class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        map<int,int> mp;
        for(auto it:nums) mp[it]++;
        int duplicate;
        for(auto it:mp) if(it.second==2) duplicate=it.first;
        int mising;
        for(int i=1;i<=nums.size();i++)
            if(mp[i]==0)
                mising=i;
        
        return {duplicate,mising};
    }
};