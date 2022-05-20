// problem link--> https://leetcode.com/problems/non-overlapping-intervals/

class Solution {
public:
    static bool comp(pair<int,int> &a,pair<int,int> &b)
    {
        if(a.second==b.second)
            return (a.first<b.first);
        return (a.second<b.second);
    }
    
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n=intervals.size();
        vector<pair<int,int>> vpr;
        for(int i=0;i<n;i++)
            vpr.push_back({intervals[i][0],intervals[i][1]});
        
        sort(vpr.begin(),vpr.end(),comp);
        
        int limit=INT_MIN;
        int cnt=0;
        
        for(int i=0;i<n;i++)
        {
            if(limit<=vpr[i].first)
            {
                cnt++;
                limit=vpr[i].second;
            }
        }
        return n-cnt;
    }
};