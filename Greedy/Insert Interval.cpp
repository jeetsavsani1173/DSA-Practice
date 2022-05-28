// problem link --> https://leetcode.com/problems/insert-interval/

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> mergedIntervals;
        if(intervals.size()==0)
            return mergedIntervals;

        sort(intervals.begin(), intervals.end());
        vector<int> tempInterval=intervals[0];

        for(auto it:intervals)
        {
            if(it[0]<=tempInterval[1])
                tempInterval[1]=max(it[1],tempInterval[1]);
            else
            {
                mergedIntervals.push_back(tempInterval);
                tempInterval=it;
            }
        }
        mergedIntervals.push_back(tempInterval);
        return mergedIntervals;
    }
    
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> ans;
        bool flag=false;
        for(int i=0;i<intervals.size();i++)
        {
            if(newInterval[0]<intervals[i][0] && !flag)
            {
                ans.push_back(newInterval);
                ans.push_back(intervals[i]);
                flag=true;
            }
            else
                ans.push_back(intervals[i]);
        }
        if(!flag)
            ans.push_back(newInterval);
        
        return merge(ans);
    }
};