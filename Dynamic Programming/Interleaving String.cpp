// problem link --> https://leetcode.com/problems/interleaving-string/

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        vector<vector<bool>> dp(s1.size()+1,vector<bool>(s2.size()+1,false));
        if(s1.size()+s2.size()!=s3.size()) return false;
        for(int i=0;i<dp.size();i++){
            for(int j=0;j<dp[i].size();j++){
                int idx=i+j-1;
                if(i==0 && j==0)
                    dp[i][j]=true;
                else if(i==0){
                    dp[i][j]=(s3[idx]==s2[j-1])?dp[i][j-1]:false;
                }else if(j==0){
                    dp[i][j]=(s3[idx]==s1[i-1])?dp[i-1][j]:false;
                }else{
                    dp[i][j]=((s3[idx]==s2[j-1])?dp[i][j-1]:false)||((s3[idx]==s1[i-1])?dp[i-1][j]:false);
                }
            }
        }
        return dp[s1.size()][s2.size()];
    }
};