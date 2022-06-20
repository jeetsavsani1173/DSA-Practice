// problem link --> https://leetcode.com/problems/maximum-score-words-formed-by-letters/

// first solution..
class Solution {
public:
    int ans;
    bool isvalid(string s,vector<char>& letters)
    {
        map<char,int> mp;
        for(auto it:letters) mp[it]++;
        
        for(auto it:s)
        {
            if(mp[it]==0)
                return false;
            mp[it]--;
        }
        return true;
    }
    int find_score(string str,vector<int> &score)
    {
        int count=0;
        for(auto it:str)
            count+=score[it-'a'];
        
        return count;
    }
    void helper(int idx,vector<string>& words,string str,vector<char>& letters, vector<int>& score)
    {
        if(idx==words.size())
        {
            if(isvalid(str,letters))
            {
                int temp_score=find_score(str,score);
                ans=max(ans,temp_score);
            }
            return;
        }
        helper(idx+1,words,str+words[idx],letters,score);
        helper(idx+1,words,str,letters,score);
    }
    int maxScoreWords(vector<string>& words,vector<char>& letters, vector<int>& score) {
        ans=INT_MIN;
        string output="";
        helper(0,words,output,letters,score);
        return ans;
    }
};

// second solution..
class Solution {
public:
    int max_score;
    bool canTake(string &s,map<char,int> &mp)
    {
        map<char,int> currMp;
        for(auto it:s) currMp[it]++;
        
        for(auto it:currMp)
        {
            if(mp[it.first]<it.second)
                return false;
        }
        return true;
    }
    int find_score(string str,vector<int> &score)
    {
        int count=0;
        for(auto it:str) count+=score[it-'a'];
        return count;
    }
    void helper(int idx,vector<string>& words,vector<int>& score,map<char,int> &mp,int CurrScore)
    {
        if(idx==words.size())
        {
            max_score=max(max_score,CurrScore);
            return;
        }
        // for Yes (Take)
        if(canTake(words[idx],mp))
        {
            for(auto it:words[idx]) mp[it]--;
            int temp_score=find_score(words[idx],score);
            helper(idx+1,words,score,mp,CurrScore+temp_score);
            for(auto it:words[idx]) mp[it]++;
        }
        
        // for No (non-take)
        helper(idx+1,words,score,mp,CurrScore);
    }
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        max_score=INT_MIN;
        map<char,int> mp;
        for(auto it:letters) mp[it]++;

        helper(0,words,score,mp,0);
        return max_score;
    }
};