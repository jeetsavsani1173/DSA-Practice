// problem link --> https://leetcode.com/problems/where-will-the-ball-fall/

class Solution {
public:
    bool isvalid(int x,int y,int n,int m){
        return (x>=0 && y>=0 && x<n && y<m);
    }
    vector<int> findBall(vector<vector<int>>& grid) {
        // bruteforce
        int n=grid.size(),m=grid[0].size();
        vector<int> ans(m,0);
        // take all column one by one and check
        for(int k=0;k<m;k++)
        {
            ans[k]=k;
            bool flag=true;
            int i=0,j=k;
            while(i<n && j<m){
                if(grid[i][j]==1){
                    if(isvalid(i,j+1,n,m) && grid[i][j+1]==1){
                        i++;
                        j++;
                    }else{
                        flag=false;
                        ans[k]=-1;
                        break;
                    }
                }else{
                    if(isvalid(i,j-1,n,m) && grid[i][j-1]==-1){
                        i++;
                        j--;
                    }else{
                        flag=false;
                        ans[k]=-1;
                        break;
                    }
                }
            }
            if(flag) ans[k]=j;
        }
        return ans;
    }
};