// problem link --> https://leetcode.com/problems/first-bad-version/

// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int left=1,right=n,ans=-1;
        
        while(left<=right)
        {
            int mid=left+(right-left)/2;
            if(isBadVersion(mid)==false)
                left=mid+1;
            else
            {
                ans=mid;
                right=mid-1;
            }
        }
        
        return ans;
    }
};