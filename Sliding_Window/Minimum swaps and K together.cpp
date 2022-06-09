// problem link --> https://practice.geeksforgeeks.org/problems/minimum-swaps-required-to-bring-all-elements-less-than-or-equal-to-k-together4847/1

class Solution
{
public:
    int minSwap(int arr[], int n, int k) {
        int cnt=0;
        for(int i=0;i<n;i++)
            if(arr[i]<=k)
                cnt++;
        int win_size=cnt;
        int curr_ans=0;
        for(int i=0;i<win_size;i++)
            if(arr[i]>k)
                curr_ans++;
            
        int ans=curr_ans;
        
        for(int i=win_size;i<n;i++)
        {
            int include=arr[i];
            int exclude=arr[i-win_size];
            
            if(include>k)
                curr_ans++;
            if(exclude>k)
                curr_ans--;
            ans=min(ans,curr_ans);
        }
        return ans;
    }
};
