// problem link --> https://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons/

class Solution {
public:
    static bool comp(pair<int,int> &a,pair<int,int> &b)
    {
        if(a.second==b.second)
            return (a.first<b.first);
        return (a.second<b.second);
    }
    
    int findMinArrowShots(vector<vector<int>>& points) {
        int n=points.size();
        vector<pair<int,int>> vpr;
        for(int i=0;i<n;i++)
            vpr.push_back({points[i][0],points[i][1]});
        
        sort(vpr.begin(),vpr.end(),comp);
        
        long limit=LONG_MIN;
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