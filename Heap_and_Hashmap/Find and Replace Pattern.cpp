// problem link --> https://leetcode.com/problems/find-and-replace-pattern/

class Solution {
public:
    bool isvalid(string &str,vector<int> &hash)
    {
        vector<int> temp(26,0);
        for(auto it:str)
            temp[it-'a']++;
        sort(temp.begin(),temp.end());
        return (temp==hash);
    }
    bool check(string &str,string &pattern)
    {
        map<char,char> mp;
        for(int i=0;i<pattern.size();i++){
            if(mp[pattern[i]]){
                if(mp[pattern[i]]!=str[i]) return false;
            }else{
                mp[pattern[i]]=str[i];
            }
        }
        
        return true;
    }
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> ans;
        vector<int> hash(26,0);
        for(int i=0;i<pattern.size();i++)
            hash[pattern[i]-'a']++;
        
        sort(hash.begin(),hash.end());
        
        for(auto it:words){
            string str=it;
            
            if(isvalid(str,hash))
                if(check(str,pattern))
                    ans.push_back(str);
        }
        return ans;
    }
};