// problem link --> https://leetcode.com/problems/out-of-boundary-paths/

// 4-dimension point
int dx4[4] = { -1, 0, 1, 0};
int dy4[4] = { 0, 1, 0, -1};
class Solution {
public:
    int M;
    int dp[51][51][51];
    int dfs(int i,int j,int m,int n,int moves)
    {
        if(!(i>=0 && i<m && j>=0 && j<n)) return 1;
        if(moves==0) return 0;
        if(dp[i][j][moves]!=-1) return dp[i][j][moves]%M;
        int count=0ll;
        for(int k=0;k<4;k++)
        {
            int newX=i+dx4[k];
            int newY=j+dy4[k];
        
            count=((count%M)+(dfs(newX,newY,m,n,moves-1)%M)%M);
        }
        // count=count%M;
        return dp[i][j][moves]=count%M;
    }
        
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        M=1e9+7;
        // memset(dp,sizeof(dp),-1);
        for(int i=0;i<51;i++) for(int j=0;j<51;j++) for(int k=0;k<51;k++) dp[i][j][k]=-1;
        return dfs(startRow,startColumn,m,n,maxMove);
    }
};