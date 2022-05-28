// problem link --> https://www.lintcode.com/problem/919

// using priority Queue
/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */
 bool comp(Interval &i1,Interval &i2)
    {
        return i1.start<i2.start;
    }

class Solution {
public:
    /**
     * @param intervals: an array of meeting time intervals
     * @return: the minimum number of conference rooms required
     */
    int minMeetingRooms(vector<Interval> &intervals) {
        if(intervals.size()<=1) return 1;
        sort(intervals.begin(),intervals.end(),comp);

        priority_queue<int, vector<int>, greater<int>> pq;
        pq.push(intervals[0].end);

        for(int i=1;i<intervals.size();i++)
        {
            if(pq.top()<=intervals[i].start)
                pq.pop();
            pq.push(intervals[i].end);
        }
        return pq.size();
    }
};

// using two pointer apporoach and optimize code

/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    /**
     * @param intervals: an array of meeting time intervals
     * @return: the minimum number of conference rooms required
     */
    int minMeetingRooms(vector<Interval> &intervals) {
        int n=intervals.size();
        vector<int> a,b;
        for(int i=0;i<n;i++)
        {
            a.push_back(intervals[i].start);
            b.push_back(intervals[i].end);
        }
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());

        int p1=0,p2=0;
        int currans=0;
        int ans=0;
        while(p1<n)
        {
            if(a[p1]==b[p2])
            {
                p1++;
                p2++;
            }
            else if(a[p1]<b[p2])
            {
                currans++;
                p1++;
            }
            else
            {
                currans--;
                p2++;
            }
            ans=max(ans,currans);
        }
        return ans;
    }
};