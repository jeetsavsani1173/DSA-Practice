// problem link --> https://leetcode.com/problems/remove-k-digits/

class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> st;
        for(int i=0;i<num.size();i++)
        {
            char curr=num[i];
            while(!st.empty() && k>0 && curr<st.top())
            {
                st.pop();
                k--;
            }
            if(!st.empty() || curr!='0')
                st.push(curr);
        }
        while(!st.empty() && k--)
            st.pop();
        if(st.size()==0)
            return "0";
        string ans;
        while(!st.empty())
        {
            ans+=st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};