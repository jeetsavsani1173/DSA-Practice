// problem link --> https://leetcode.com/problems/minimum-index-sum-of-two-lists/

class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        map<string,int> for_sum;
        map<string,int> mp;
        
        for(auto it:list1) mp[it]++;
        for(auto it:list2) mp[it]++;
        for(int i=0;i<list1.size();i++)
            for_sum[list1[i]]+=i;
        for(int i=0;i<list2.size();i++)
            for_sum[list2[i]]+=i;
        
        int mn=INT_MAX;
        for(auto it:mp)
            if(it.second==2)
                mn=min(mn,for_sum[it.first]);
        
        vector<string> ans;
        for(auto it:for_sum)
        {
            if(it.second==mn && mp[it.first]==2)
                ans.push_back(it.first);
        }
        return ans;
    }
};