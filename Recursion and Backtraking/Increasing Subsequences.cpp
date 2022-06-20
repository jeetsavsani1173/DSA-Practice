// problem link --> https://leetcode.com/problems/increasing-subsequences/

class Solution {
public:
    set<vector<int>> ans;
    bool issorted(vector<int> &vect)
    {
        for(int i=1;i<vect.size();i++)
            if(vect[i-1]>vect[i])
                return false;
        return true;
    }
    void helper(int idx,vector<int>&nums,vector<int> &temp)
    {
        if(idx==nums.size())   
        {
            if(temp.size()>1 && issorted(temp))
                ans.insert(temp);
            return;
        }
        // Take..
        temp.push_back(nums[idx]);
        helper(idx+1,nums,temp);
        temp.pop_back();
        
        // Non-Take
        helper(idx+1,nums,temp);
    }
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<int> temp;
        helper(0,nums,temp);
        vector<vector<int>> res;
        for(auto it:ans) res.push_back(it);
        return res;
    }
};