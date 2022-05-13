// problem link -->    https://practice.geeksforgeeks.org/problems/row-with-max-1s0023/1

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++
class Solution{
public:
	int rowWithMax1s(vector<vector<int> > arr, int n, int m) {
	    int l=0,r=m-1;
	    int ans=-1,numberOfones=0;
	    
	    for(int i=0;i<n;i++)
	    {
	        if(arr[i][r]==0)
	            continue;
	        int TransitionPoint=lower_bound(arr[i].begin()+l,arr[i].end()+r,1)-arr[i].begin();
	        
	        if(m-TransitionPoint > numberOfones)
	        {
	            numberOfones=m-TransitionPoint;
	            ans=i;
	        }
	        r=TransitionPoint;
	    }
	    
	    return ans;
	}

};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector< vector<int> > arr(n,vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin>>arr[i][j];
            }
        }
        Solution ob;
        auto ans = ob.rowWithMax1s(arr, n, m);
        cout << ans << "\n";
    }
    return 0;
}
  // } Driver Code Ends