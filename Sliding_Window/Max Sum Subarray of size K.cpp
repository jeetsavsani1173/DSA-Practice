// problem link --> https://practice.geeksforgeeks.org/problems/max-sum-subarray-of-size-k5313/1

class Solution{   
public:
    long long maximumSumSubarray(int K, vector<int> &Arr , int N){
        long long curr_sum=0;
        for(int i=0;i<K;i++)
            curr_sum+=Arr[i];
        
        long long ans=curr_sum;
        int i=K;
        while(i<N)
        {
            curr_sum+=(Arr[i]-Arr[i-K]);
            i++;
            ans=max(ans,curr_sum);
        }
        
        return ans;
    }
};