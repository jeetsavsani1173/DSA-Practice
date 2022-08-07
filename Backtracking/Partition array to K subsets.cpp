// problem link --> https://practice.geeksforgeeks.org/problems/partition-array-to-k-subsets/1

class Solution{
  public:
    bool ans;
    void helper(int a[],int n,int k,int currSum,int count,vector<bool> &vis,int target)
    {
        if(count==k-1){
            ans=true;
            return;
        }
        if(currSum>target) return;
        if(currSum==target){
            helper(a,n,k,0,count+1,vis,target);
            if(ans) return;
        }
        
        for(int i=0;i<n;i++){
            if(!vis[i]){
                vis[i]=true;
                helper(a,n,k,currSum+a[i],count,vis,target);
                if(ans) return;
                vis[i]=false;
            }
        }
    }
    bool isKPartitionPossible(int a[], int n, int k)
    {
         if(k>n) return false;
         if(k==1) return true;
         int sum=0;
         for(int i=0;i<n;i++) sum+=a[i];
         if(sum%k) return false;
         vector<bool> vis(n,false); 
         ans=false;
         helper(a,n,k,0,0,vis,sum/k);
         return ans;
    }
};