// problem link --> https://leetcode.com/problems/find-common-characters/

class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        vector<vector<int>> hash(words.size(),vector<int>(26,0));
        
        for(int i=0;i<words.size();i++)
        {
            for(auto it:words[i])
            {
                hash[i][it-'a']++;
            }
        }
        vector<string> ans;
        for(int j=0;j<26;j++)
        {
            int MinFreq=INT_MAX;
            for(int i=0;i<hash.size();i++)
            {
                MinFreq=min(MinFreq,hash[i][j]);
            }
            
            string temp;
            temp.push_back('a'+j);
            while(MinFreq--) ans.push_back(temp);
        }
        return ans;
    }
};