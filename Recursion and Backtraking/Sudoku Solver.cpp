// problem link --> https://leetcode.com/problems/sudoku-solver/

 class Solution {
public:
    bool isvalidSudoku(vector<vector<char>>& board,int row,int col,char ch)
    {
        // check for row element..
        for(int j=0;j<9;j++){
            if(board[row][j]==ch)
                return false;
        }
        
        // check for column element..
        for(int i=0;i<9;i++){
            if(board[i][col]==ch)
                return false;
        }
        
        // check for submatrix element..
        int subRow=row/3;
        int subCol=col/3;
        
        int newRow=subRow*3;
        int newCol=subCol*3;
        
        for(int i=newRow;i<newRow+3;i++)
        {
            for(int j=newCol;j<newCol+3;j++)
            {
                if(board[i][j]==ch)
                    return false;
            }
        }
        return true;
    }
    bool solveSudoku(vector<vector<char>>& board,int row,int col)
    {
        if(row==9) return true;
        
        int nextRow=(col==8)?row+1:row;
        int nextCol=(col==8)?0:col+1;
        
        if(board[row][col]!='.'){
            bool res=solveSudoku(board,nextRow,nextCol);
            if(res) return true;
        }else{
            for(char ch='1';ch<='9';ch++){
                if(isvalidSudoku(board,row,col,ch))
                {
                    board[row][col]=ch;
                    bool res=solveSudoku(board,nextRow,nextCol);
                    if(res) return true;
                    board[row][col]='.';
                }
            }
        }
        
        return false;
    }
    void solveSudoku(vector<vector<char>>& board) {
        solveSudoku(board,0,0);
    }
};