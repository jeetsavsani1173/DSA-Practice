// problem link --> https://leetcode.com/problems/interval-list-intersections/

class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        vector<vector<int>> ans;
        int firstIdx=0,secondIdx=0;
        
        while(firstIdx<firstList.size() && secondIdx<secondList.size())
        {
            int s1=firstList[firstIdx][0];
            int e1=firstList[firstIdx][1];
            int s2=secondList[secondIdx][0];
            int e2=secondList[secondIdx][1];
            
            int start=max(s1,s2);
            int end=min(e1,e2);
            
            if(start<=end)
            {
                ans.push_back({start,end});
            }
            
            if(e1<e2)
                firstIdx++;
            else
                secondIdx++;
        }
        return ans;
    }
};