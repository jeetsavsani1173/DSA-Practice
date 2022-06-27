// problem link --> https://leetcode.com/problems/maximum-points-you-can-obtain-from-cards/

class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        vector<int> pref(cardPoints.size()+1,0);
        for(int i=1;i<=cardPoints.size();i++)
            pref[i]=pref[i-1]+cardPoints[i-1];
        
        int ans=INT_MIN;
        
        for(int i=0;i<=k;i++)
        {
            int sum=pref[i];
            sum+=(pref[pref.size()-1]-pref[pref.size()-1-k+i]);
            
            ans=max(ans,sum);
        }
        return ans;
    }
};