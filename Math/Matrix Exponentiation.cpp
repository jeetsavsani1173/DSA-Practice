// problem link --> https://practice.geeksforgeeks.org/problems/matrix-exponentiation2711/1#

class Solution {
public:
    int M;
    unordered_map<long,vector<long>> vmp;
    vector<long> multiply(vector<long> &a,vector<long> &b)
    {
        vector<long> ans(4,0);
        ans[0]=(a[0]*b[0]+a[1]*b[2])%M;
        ans[1]=(a[0]*b[1]+a[1]*b[3])%M;
        ans[2]=(a[2]*b[0]+a[3]*b[2])%M;
        ans[3]=(a[2]*b[1]+a[3]*b[3])%M;
        return ans;
    }
    void find(long long int n)
    {
        vector<long> v={1,1,1,0};
        vmp[0]=v;
        int cnt=0;
        while((1<<cnt)<=n)
        {
            vector<long> temp=vmp[cnt];
            vector<long> ans=multiply(temp,temp);
            cnt++;
            vmp[cnt]=ans;
        }
    }
    int FindNthTerm(long long int n) {
        M=1e9+7;
        find(n+1);
        bool flag=false;
        vector<long> ans;
        for(int bit=0;bit<32;bit++)
        {
            if((1<<bit)&n)
            {
                if(!flag){
                    ans=vmp[bit];
                    flag=true;
                }
                else{
                    ans=multiply(ans,vmp[bit]);
                }
            }
        }
        return (int)ans[0];
    }
};