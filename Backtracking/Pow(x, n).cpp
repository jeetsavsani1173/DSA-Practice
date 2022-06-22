// problem link -->> https://leetcode.com/problems/powx-n/

class Solution {
public:
    double myPow(double x, int n) {
        if(n<0) return 1/x * myPow(1/x, -(n+1));
        if(n==0)
            return 1.00000;
        
        if(n%2==0)
            return myPow(x*x,n/2);
        else
            return (x*myPow(x*x,(n-1)/2));
        
    }
};