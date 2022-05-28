// problem link --> https://leetcode.com/problems/car-fleet/

class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n=speed.size();
        vector<pair<int,int>> vpr;
        for(int i=0;i<position.size();i++)
            vpr.push_back({position[i],speed[i]});
        sort(vpr.begin(),vpr.end());
        
        double maxTime=(target-vpr[n-1].first)/(double)vpr[n-1].second;
        int cnt=1;
        
        for(int i=n-2;i>=0;i--)
        {
            double tempTime=(target-vpr[i].first)/(double)vpr[i].second;
            
            if(tempTime>maxTime)
            {
                maxTime=tempTime;
                cnt++;
            }
        }
        return cnt;
    }
};