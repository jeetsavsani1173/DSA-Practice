// problem link --> https://leetcode.com/problems/determine-whether-matrix-can-be-obtained-by-rotation/

class Solution {
public:
    void rotate90degree(vector<vector<int>>& matrix) {
        int n=matrix.size();
        
        for(int i=0;i<n;i++)
            for(int j=0;j<i;j++)
                swap(matrix[i][j],matrix[j][i]);
        
        for(int i=0;i<n;i++)
            reverse(matrix[i].begin(),matrix[i].end());
    }
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        vector<vector<int>> temp=mat;
        for(int i=0;i<4;i++)
        {
            rotate90degree(temp);
            if(temp==target)
                return true;
            if(temp==mat)
                break;
        }
        return false;
    }
};