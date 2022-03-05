// probelm link -->  https://leetcode.com/problems/gray-code/

class Solution {
public:
    int convert_to_INT(string s)
    {
        int ans=0;
        int cnt=0;
        for(int i=s.size()-1;i>=0;i--)
        {
            if(s[i]=='1')
                ans+=(1<<cnt);
            cnt++;
        }
        return ans;
    }


    vector<string> rec(int n)
    {
        if(n==1)
        {
            vector<string> bres;
            bres.push_back("0");
            bres.push_back("1");
            return bres;
        }

        vector<string> rres=rec(n-1);

        vector<string> ans;

        for(int i=0;i<rres.size();i++)
            ans.push_back("0"+rres[i]);

        for(int i=rres.size()-1;i>=0;i--)
            ans.push_back("1"+rres[i]);

        return ans;
    }

    vector<int> grayCode(int n) {
        vector<int> ans;
        vector<string> bits=rec(n);
        for(int i=0;i<bits.size();i++)
        {
            ans.push_back(convert_to_INT(bits[i]));
        }
        return ans;
    }
};