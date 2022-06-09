// problem link --> https://www.interviewbit.com/problems/array-3-pointers

int Solution::minimize(const vector<int> &A, const vector<int> &B, const vector<int> &C) {
    int i=0,j=0,k=0;

    int ans=INT_MAX;

    while(i < A.size() && j < B.size() && k < C.size())
    {
        int temp_ans=max(abs(A[i]-B[j]),max(abs(B[j]-C[k]),abs(C[k]-A[i])));
        ans=min(ans,temp_ans);

        if(A[i]<=B[j] && A[i]<=C[k]) i++;
        else if(B[j]<=A[i] && B[j]<=C[k]) j++;
        else k++;
    }
    return ans;
}
