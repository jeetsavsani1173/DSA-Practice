// problem link --> https://leetcode.com/problems/substring-with-concatenation-of-all-words/

class Solution {
public:
    bool issame(vector<int> &vect1,vector<int> &vect2)
    {
        for(int i=0;i<26;i++) if(vect1[i]!=vect2[i]) return false;
        return true;
    }
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> hash(26,0);
        for(auto it:words) for(auto it1:it) hash[it1-'a']++;
        int Window_Size=words.size()*words[0].size();
        vector<int> W_hash(26,0);
        map<string,int> mps;
        for(auto it:words) mps[it]++;
        if(s.size()<Window_Size) return {};
        for(int i=0;i<Window_Size;i++) W_hash[s[i]-'a']++;
        vector<int> ans;
        
        
        int i=0;
        for(;i<=s.size()-Window_Size;i++)
        {
            if(issame(W_hash,hash)){
                map<string,int> mp=mps;
                int pos=i;
                int end=i+Window_Size;
                bool flag=true;
                while(pos<end){
                    string temp=s.substr(pos,words[0].size());
                    pos+=words[0].size();
                    if(mp[temp]==0){
                        flag=false;
                        break;
                    }else{
                        mp[temp]--;
                    }
                    
                }
                if(flag) ans.push_back(i);
            }
            W_hash[s[i]-'a']--;
            if(i+Window_Size<s.size())
                W_hash[s[i+Window_Size]-'a']++;
        }
        
        return ans;
    }
};