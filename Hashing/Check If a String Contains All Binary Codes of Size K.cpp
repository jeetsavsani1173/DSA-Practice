// problem link --> https://leetcode.com/problems/check-if-a-string-contains-all-binary-codes-of-size-k/

class Solution {
public:
    bool hasAllCodes(string s, int k) {
        int n=s.size();
        unordered_set<string> st;
        
        for(int i=0;i<=(n-k);i++)
        {
            string temp=s.substr(i,k);
            st.insert(temp);
        }
        
        return st.size()==(1<<k);
    }
};