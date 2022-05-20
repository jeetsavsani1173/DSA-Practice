// problem link --> https://leetcode.com/problems/maximum-length-of-pair-chain/

class Solution {
public:
    static bool comp(pair<int,int> &a,pair<int,int> &b)
    {
        if(a.second==b.second)
            return (a.first<b.first);
        return (a.second<b.second);
    }
    
    int findLongestChain(vector<vector<int>>& pairs) {
        int n=pairs.size();
        vector<pair<int,int>> vpr;
        for(int i=0;i<n;i++)
            vpr.push_back({pairs[i][0],pairs[i][1]});
        
        sort(vpr.begin(),vpr.end(),comp);
        
        int limit=INT_MIN;
        int cnt=0;
        
        for(int i=0;i<n;i++)
        {
            if(limit<vpr[i].first)
            {
                cnt++;
                limit=vpr[i].second;
            }
        }
        return cnt;
    }
};