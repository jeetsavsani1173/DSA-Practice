// problem link --> https://leetcode.com/problems/candy/

class Solution {
public:
    int candy(vector<int>& ratings) {
        int n=ratings.size();
        vector<int> left(n,1);
        vector<int> right(n,1);
        
        // from left to right
        for(int i=1;i<n;i++)
        {
            if(ratings[i-1]<ratings[i])
                left[i]=1+left[i-1];
        }
        
        // from right to left
        for(int i=n-2;i>=0;i--)
        {
            if(ratings[i]>ratings[i+1])
                right[i]=1+right[i+1];
        }
        int ans=0;
        for(int i=0;i<n;i++)
            ans+=max(left[i],right[i]);
        return ans;
    }
};