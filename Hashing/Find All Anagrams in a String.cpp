// problem link --> https://leetcode.com/problems/find-all-anagrams-in-a-string/

// first solution
class Solution {
public:
    vector<int> find_hash(string &s,int i,int j)
    {
        vector<int> hash(26,0);
        
        for(int k=i;k<=j;k++)
            hash[s[k]-'a']++;
        
        return hash;
    }
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
        if(p.size()>s.size())
            return ans;
        vector<int> phash(26,0);
        for(auto it:p)
            phash[it-'a']++;
        
        int i=0;
        while(i<=(s.size()-p.size()))
        {
            vector<int> hash=find_hash(s,i,i+p.size()-1);
            if(hash==phash)
                ans.push_back(i);
            i++;
        }
        return ans;
    }
};


//second solution
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
        if(p.size()>s.size())
            return ans;
        vector<int> phash(26,0);
        for(auto it:p)
            phash[it-'a']++;
        int k=p.size();
        vector<int> hash(26,0);
        for(int i=0;i<k;i++)
            hash[s[i]-'a']++;
        
        int left=0;
        int right=k-1;
        while(right<s.size())
        {
            if(hash==phash)
                ans.push_back(left);
            right++;
            if(right!=s.size())
                hash[s[right]-'a']++;
            hash[s[left]-'a']--;
            left++;
        }
        return ans;
    }
};