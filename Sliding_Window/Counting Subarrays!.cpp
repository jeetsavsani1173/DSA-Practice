// problem link --> https://www.interviewbit.com/problems/counting-subarrays/

int Solution::solve(vector<int> &A, int B) {
    int count=0,CurrSum=0,left=0;

    for(int right=0;right<A.size();right++)
    {
        CurrSum+=A[right];
        while(CurrSum>=B){
            CurrSum-=A[left];
            left++;
        }
        count+=(right-left+1);
    }
    return count;
}
