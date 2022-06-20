// problem link --> https://leetcode.com/problems/lexicographical-numbers/

class Solution {
public:
    void helper(int num,int n,vector<int>&ans)
    {
        if(num>n) return;
        if(num!=0) ans.push_back(num);
        for(int i=0;i<10;i++)
        {
            if(i==0 && num==0)
                continue;
            else
                helper(num*10+i,n,ans);
        }
    }
    vector<int> lexicalOrder(int n) {
        vector<int> ans;
        helper(0,n,ans);
        return ans;
    }
};