// problem link --> https://leetcode.com/problems/toeplitz-matrix/

class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int n=matrix.size(),m=matrix[0].size();
        
        for(int i=0;i<n;i++)
        {
            int temp=matrix[i][0];
            int j=i,k=0;
            while(j<n && k<m){
                if(matrix[j][k]!=temp) return false;
                j++;
                k++;
            }
        }
        
        for(int i=0;i<m;i++)
        {
            int temp=matrix[0][i];
            int j=0,k=i;
            while(j<n && k<m){
                if(matrix[j][k]!=temp) return false;
                j++;
                k++;
            }
        }
        
        return true;
    }
};