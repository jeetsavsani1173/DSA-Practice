// problem link --> https://leetcode.com/problems/intersection-of-two-arrays-ii/

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        map<int,int> mp1,mp2;
        for(auto it:nums1) mp1[it]++;
        for(auto it:nums2) mp2[it]++;
        
        vector<int> ans;
        
        for(auto it:mp1)
        {
            if(mp2[it.first]>0)
            {
                int temp=min(mp2[it.first],it.second);
                while(temp--) ans.push_back(it.first);
            }
        }
        return ans;
    }
};