// problem link --> https://leetcode.com/problems/maximum-area-of-a-piece-of-cake-after-horizontal-and-vertical-cuts/

class Solution {
public:
    int M=1e9+7;
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts)     {
        verticalCuts.push_back(0);verticalCuts.push_back(w);
        horizontalCuts.push_back(0);horizontalCuts.push_back(h);
        sort(horizontalCuts.begin(),horizontalCuts.end());
        sort(verticalCuts.begin(),verticalCuts.end());
        int ans1=0;
        for(int i=0;i<horizontalCuts.size()-1;i++)
            ans1=max(ans1,horizontalCuts[i+1]-horizontalCuts[i]);
        
        int ans2=0;
        for(int i=0;i<verticalCuts.size()-1;i++)
            ans2=max(ans2,verticalCuts[i+1]-verticalCuts[i]);
        
        return (int)((1ll*ans1*ans2)%M);
    }
};