// problem link --> https://leetcode.com/problems/ugly-number-ii/

// using Three-pointer Techniqe
class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> dp;
        dp.push_back(0);
        dp.push_back(1);
        int ptr2=1,ptr3=1,ptr5=1;
        
        for(int i=2;i<=n;i++)
        {
            int a=dp[ptr2]*2;
            int b=dp[ptr3]*3;
            int c=dp[ptr5]*5;
            
            int mn=min(a,min(b,c));
            dp.push_back(mn);
            
            if(mn==a) ptr2++;
            if(mn==b) ptr3++;
            if(mn==c) ptr5++;
        }
        
        return dp[n];
    }
};

// using Priority-Queue
class Solution {
public:
    int nthUglyNumber(int n) {
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
            pq.push(2ll*val);
            pq.push(3ll*val);
            pq.push(5ll*val);
        }
        return val;
    }
};