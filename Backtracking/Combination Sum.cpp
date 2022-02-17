// problem link --> https://leetcode.com/problems/combination-sum/

// solution
class Solution {
public:
    void find_combination(vector<int> &v,int index,int target,vector<int> &ds,vector<vector<int>> &ans)
    {
        if(index==v.size())
        {
            if(target==0)
            {
                ans.push_back(ds);
            }
            return;
        }
        
        // take element
        if(v[index]<=target)
        {
            ds.push_back(v[index]);
            find_combination(v,index,target-v[index],ds,ans);
            ds.pop_back(); // backtrack element from ds
        }
        
        // not-take element
        find_combination(v,index+1,target,ds,ans);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> ds;
        find_combination(candidates,0,target,ds,ans);
        return ans;
    }
};