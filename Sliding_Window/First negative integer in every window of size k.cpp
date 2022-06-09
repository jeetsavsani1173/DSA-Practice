// problem link --> https://practice.geeksforgeeks.org/problems/first-negative-integer-in-every-window-of-size-k3345/1

vector<long long> printFirstNegativeInteger(long long int A[],
                                             long long int N, long long int K) {
        queue<long long> q;
        vector<long long> ans;
        
        for(long long i=0;i<K;i++)
            if(A[i]<0)
                q.push(A[i]);
            
        ans.push_back(q.size()>0?q.front():0ll);
        for(long long i=K;i<N;i++)
        {
            if(A[i]<0) q.push(A[i]);
            if(A[i-K]<0) q.pop();
            
            ans.push_back(q.size()>0?q.front():0ll);
        }
        return ans;
 }