// problem link --> https://www.lintcode.com/problem/920/

bool comp(Interval &i1,Interval &i2)
    {
        if((i1.start) == (i2.start))
            return (i1.end) < (i2.end);
        else
            return (i1.start) < (i2.start);
    }

class Solution {
public:
    /**
     * @param intervals: an array of meeting time intervals
     * @return: if a person could attend all meetings
     */ 
    bool canAttendMeetings(vector<Interval> &intervals) {
        if(intervals.size()<=1) return true;
        sort(intervals.begin(),intervals.end(),comp);

        for(int i=1;i<intervals.size();i++)
        {
            if(intervals.at(i).start < intervals.at(i - 1).end)
                return false;
        }
        return true;
    }
};