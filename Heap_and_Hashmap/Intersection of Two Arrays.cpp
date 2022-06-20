// problem link --> https://leetcode.com/problems/intersection-of-two-arrays/

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        set<int> st1,st2;
        for(auto it:nums1) st1.insert(it);
        for(auto it:nums2) st2.insert(it);
        
        vector<int> ans;
        for(auto it:st1)
            if(st2.find(it)!=st2.end())
                ans.push_back(it);
        
        return ans;
    }
};