// problem link --> https://leetcode.com/problems/word-subsets/

class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<int> freq(26,0);
        for(auto it:words2)
        {
            vector<int> temp(26,0);
            for(auto it1:it)
                temp[it1-'a']++;
            
            for(int i=0;i<26;i++)
                freq[i]=max(freq[i],temp[i]);
        }
        
        // for(auto it:freq)
        //     cout<<it<<" ";
        // cout<<endl;
        
        vector<string> ans;
        for(auto it:words1)
        {
            vector<int> temp(26,0);
            for(auto it1:it)
                temp[it1-'a']++;
            
            bool flag=true;
            for(int i=0;i<26;i++){
                if(freq[i]>temp[i])
                    flag=false;
            }
            if(flag) ans.push_back(it);
        }
        return ans;
    }
};