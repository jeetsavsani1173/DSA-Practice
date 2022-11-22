// problem link --> https://leetcode.com/problems/numbers-with-same-consecutive-differences/

class Solution {
public:
    vector<int> ans;
    int convert(vector<int> &v)
    {
        int count=v[0];
        for(int i=1;i<v.size();i++)
        {
            count=count*10+v[i];
        }
        return count;
    }
    void helper(int idx,vector<int> &v,int n,int k)
    {
        if(idx==n){
            int temp=convert(v);
            ans.push_back(temp);
            return;
        }
        // for decrese number..
        if((v[idx-1]-k)>=0){
            v[idx]=v[idx-1]-k;
            helper(idx+1,v,n,k);
            v[idx]=0;
        }
        
        // for increase number..
        if((v[idx-1]+k)<10 && k!=0){
            v[idx]=v[idx-1]+k;
            helper(idx+1,v,n,k);
            v[idx]=0;
        }
    }
    vector<int> numsSameConsecDiff(int n, int k) {
        vector<int> v(n,0);
        
        for(int i=1;i<=9;i++)
        {
            v[0]=i;
            helper(1,v,n,k);
            v[0]=0;
        }
        return ans;
    }
};