// problem link --> https://leetcode.com/problems/remove-covered-intervals/

// bruteforce TC:O(N^2)
class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        set<pair<int,int>> stpr;
        int n=intervals.size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i==j)
                    continue;
                
                if(intervals[i][0]<=intervals[j][0] && intervals[i][1]>=intervals[j][1])
                    stpr.insert({intervals[j][0],intervals[j][1]});
                
            }
        }
        
        return n-stpr.size();
    }
};

// optimize TC: O(nlogn)
class Solution {
public:
    static bool comp(const vector<int> &a,const vector<int> &b)
    {
        if(a[0]==b[0])
            return (a[1]>b[1]);
        else 
            return (a[0]<b[0]);
    }
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        int remove_cnt=0;
        int n=intervals.size();
        sort(intervals.begin(), intervals.end(),comp);
        vector<int> tempInterval=intervals[0];
        // cout<<intervals[0]<<endl;
        for(auto it:intervals)
        {
            if (it[1] <= tempInterval[1])
            {
                if(it[1]==tempInterval[1])
                {
                    if(it[0]!=tempInterval[0])
                        remove_cnt++;
                }
                else
                    remove_cnt++;
            }
            else
                tempInterval=it;
        }
        
        return n- remove_cnt;
    }
};

