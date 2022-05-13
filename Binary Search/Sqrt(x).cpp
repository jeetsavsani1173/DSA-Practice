// problem link --> https://leetcode.com/problems/sqrtx/

class Solution {
public:
    int mySqrt(int x) {
        if(x==0) return 0;
        long l=1ll,r=x,ans=1ll;
        
        while(l<=r)
        {
            long mid=l+(r-l)/2ll;
            long square=mid*mid;
            
            if(square==x)
                return (int)mid;
            else if(square < x){
                ans=mid;
                l=mid+1;
            }else{
                r=mid-1;
            }
        }
        return (int)ans;
    }
};