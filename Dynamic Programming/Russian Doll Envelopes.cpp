// problem link --> https://leetcode.com/problems/russian-doll-envelopes/

// DP + Binary Search on LIS
class Solution {
public:
    static bool comp(pair<int,int> &a,pair<int,int> &b)
    {
        if(a.first==b.first)
            return b.second < a.second;
        
        return a.first < b.first;
    }
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        int n=envelopes.size();
        vector<pair<int,int>> vpr;
        for(int i=0;i<envelopes.size();i++)
            vpr.push_back({envelopes[i][0],envelopes[i][1]});
        if (vpr.empty()) return 0;
        sort(vpr.begin(), vpr.end(),comp);
        
        vector<int> dp;
        dp.push_back(vpr[0].second);
        for(int i=1;i<n;i++)
        {
            if(dp.back()<vpr[i].second)
                dp.push_back(vpr[i].second);
            else {
                int it=lower_bound(dp.begin(),dp.end(),vpr[i].second)-dp.begin();
                dp[it]=vpr[i].second;
            }
        }
        return dp.size();
    }
};