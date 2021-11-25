// problem link -->>  https://leetcode.com/problems/number-of-matching-subsequences/

class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        int i,j,k,count=0;
        for(i=0;i<words.size();i++)
        {
            k=-1;
            bool ok=true;
            for(j=0;j<words[i].length();j++)
            {
                k=s.find(words[i][j],k+1);
                if(k==-1)
                {
                    ok=false;
                    break;
                }
            }
            if(ok)
            {
                count++;
            }
        }
        return count;
    }
};