// problem link --> https://leetcode.com/problems/spiral-matrix/

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
    vector<int> ans;
    int minr=0;
    int minc=0;
    
    int maxr=matrix.size()-1;
    int maxc=matrix[0].size()-1;
    
    int tne=(maxr+1)*(maxc+1);
    int cnt=0;
    
    while(cnt<tne)
    {
        for(int j = minc; j <= maxc && cnt < tne; j++){
            //cout<<arr[minr][j]<<endl;
             ans.push_back(matrix[minr][j]);
            cnt++;
         }
         minr++;
        
        for(int i = minr; i <= maxr && cnt < tne; i++){
            //cout<<arr[i][maxc]<<endl;
             ans.push_back(matrix[i][maxc]);
            cnt++;
         }
         maxc--;

        
         for(int j = maxc; j >= minc && cnt < tne; j--){
            //cout<<arr[maxr][j]<<endl;
             ans.push_back(matrix[maxr][j]);
            cnt++;
         }
         maxr--;
        
        for(int i = maxr; i >= minr && cnt < tne; i--){
            //cout<<arr[i][minc]<<endl;
            ans.push_back(matrix[i][minc]);
            cnt++;
         }
         minc++;
        
    }
        
        return ans;
    }
};