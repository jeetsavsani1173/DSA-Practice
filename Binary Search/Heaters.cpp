// problem link --> https://leetcode.com/problems/heaters/

class Solution {
public:
    int closest(vector<int> &heaters,int target)
    {
        int lw=lower_bound(heaters.begin(),heaters.end(),target)-heaters.begin();
        if(lw==0)
            return heaters[0];
        else if(lw==heaters.size())
            return heaters[heaters.size()-1];
        else
        {
            if(abs(target-heaters[lw])>abs(target-heaters[lw-1]))
                return heaters[lw-1];
            else
                return heaters[lw];
        }
    }
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        sort(heaters.begin(),heaters.end());
        
        int Max_ans=INT_MIN;
        
        for(int i=0;i<houses.size();i++)
        {
            int closestHeater=closest(heaters,houses[i]);
            Max_ans=max(Max_ans,abs(closestHeater-houses[i]));
        }
        
        return Max_ans;
    }
};