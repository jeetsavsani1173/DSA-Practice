// problem link --> https://leetcode.com/problems/divide-two-integers/

class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend==(1<<31) && divisor==-1) return INT_MAX;
        
        int sign=(dividend>=0)==(divisor>=0)?1:-1;
        
        dividend=abs(dividend);
        divisor=abs(divisor);
        long result=0;
        while(1ll*dividend-divisor >= 0){
            long count=0;
            while((1ll*dividend-(1ll*divisor<<1ll<<count)) >=0){
                // divisor<<1<<count == divisor*(2^count)
                count++;
            }
            result+=(1ll<<count);
            dividend-=(divisor*1ll<<count);
        }
        return result*sign;
    }
};
