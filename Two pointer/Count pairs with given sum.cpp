// problem link --> https://practice.geeksforgeeks.org/problems/count-pairs-with-given-sum5022/1#


class Solution{   
public:
    int getPairsCount(int arr[], int n, int k) {
        map<int,int> mp;
        int ans=0;
        for(int i=0;i<n;i++)
        {
            ans+=mp[k-arr[i]];
            mp[arr[i]]++;
        }
        
        return ans;
    }
};