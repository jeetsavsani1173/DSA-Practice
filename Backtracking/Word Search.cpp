// problem link --> https://leetcode.com/problems/word-search/

int dx[4] = { -1, 0, 1, 0};
int dy[4] = { 0, 1, 0, -1};

class Solution {
public:
    bool flag;
    vector<vector<bool>> vis;
    void dfs(int r,int c,int n,int m,int idx,string &word,vector<vector<char>>& board)
    {
        if(idx==(word.size()-1)){
            if(board[r][c]==word[word.size()-1]){
                flag=true;
            }
            return;
        }
        if(board[r][c]!=word[idx]) 
        {
            return;
        }
        
        for(int i=0;i<4;i++)
        {
            int newX=r+dx[i];
            int newY=c+dy[i];
            
            if(newX>=0 && newY>=0 && newX<n && newY<m && !vis[newX][newY])
            {
                vis[newX][newY]=true;
                dfs(newX,newY,n,m,idx+1,word,board);
                vis[newX][newY]=false;
            }
        }
    }
    bool exist(vector<vector<char>>& board, string word) {
        int n=board.size(),m=board[0].size();
        vis=vector<vector<bool>>(n,vector<bool>(m,false));
        flag=false;
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
            {
                if(board[i][j]==word[0]){
                    vis[i][j]=true;
                    dfs(i,j,n,m,0,word,board);
                    vis[i][j]=false;
                }
            }
        return flag;
    }
};