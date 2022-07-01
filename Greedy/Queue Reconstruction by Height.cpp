// problem link --> https://leetcode.com/problems/queue-reconstruction-by-height/

class Solution {
public:
    static bool comp(vector<int> &a,vector<int> &b)
    {
        if(a[0]==b[0]) return a[1]<b[1];
        else return a[0]<b[0];
    }
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        int n=people.size();
        sort(people.begin(),people.end(),comp);
        
        vector<vector<int>> ans(n,vector<int>(2,-1));
        
        for(int i=0;i<n;i++)
        {
            int count=people[i][1];
            for(int j=0;j<n;j++)
            {
                if(count==0 && ans[j][0]==-1){
                    ans[j][0]=people[i][0];
                    ans[j][1]=people[i][1];
                    break;
                }else if(ans[j][0]==-1 || ans[j][0]>=people[i][0])
                    count--;
            }
        }
        return ans;
    }
};