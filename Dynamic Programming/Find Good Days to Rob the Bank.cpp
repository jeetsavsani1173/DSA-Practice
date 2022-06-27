// problem link --> https://leetcode.com/problems/find-good-days-to-rob-the-bank/

class Solution {
public:
    vector<int> goodDaysToRobBank(vector<int>& security, int time) {
        int n=security.size();
        vector<int> dp_left(n,1);
        vector<int> dp_right(n,1);
        for(int i=1;i<n;i++)
            dp_left[i]=(security[i-1]>=security[i])?(dp_left[i-1]+1):1;
        
        for(int i=n-2;i>=0;i--)
            dp_right[i]=(security[i]<=security[i+1])?(dp_right[i+1]+1):1;
        
        vector<int> idx;
        for(int i=0;i<n;i++)
        {
            if(((dp_left[i]-1)>=time) && ((dp_right[i]-1)>=time))
                idx.push_back(i);
        }
        return idx;
    }
};