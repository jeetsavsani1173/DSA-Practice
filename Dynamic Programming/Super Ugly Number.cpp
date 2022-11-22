// problem link --> https://leetcode.com/problems/super-ugly-number/

class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        priority_queue<long, vector<long>, greater<long> > pq;
        pq.push(1);
        int nth=0;
        long val;
        while(!pq.empty() && nth<n)
        {
            val=pq.top();
            pq.pop();
            while(!pq.empty() && val==pq.top()) 
                pq.pop();
            nth++;
            
            for(auto it:primes)
                pq.push(val*it);
        }
        return val;
    }
};