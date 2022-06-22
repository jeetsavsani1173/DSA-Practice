// problem link --> https://leetcode.com/problems/k-th-symbol-in-grammar/

class Solution {
public:
    int kthGrammar(int n, int k) {
        if(n==1) return 0;
        if(k&1){
            return (kthGrammar(n-1,(k+1)/2)==1)?1:0;
        }else{
            return (kthGrammar(n-1,k/2)==1)?0:1;
        }
    }
};