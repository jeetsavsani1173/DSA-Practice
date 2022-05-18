// problem link --> https://leetcode.com/problems/koko-eating-bananas/

class Solution {
public:
    int cost_function(vector<int> &piles,int k)
    {
        int ans=0;
        
        for(int i=0;i<piles.size();i++)
        {
            ans+=ceil(1.0*piles[i]/k);
        }
        return ans;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int low=1,high=*max_element(piles.begin(),piles.end());
        int ans=high;
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            
            if(cost_function(piles,mid)<=h)
            {
                ans=mid;
                high=mid-1;
            }
            else
                low=mid+1;
        }
        return ans;
    }
};