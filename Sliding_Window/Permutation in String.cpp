// problem link --> https://leetcode.com/problems/permutation-in-string/

// solution

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int k=s1.size();
        int len=s2.size();
        
        if(k>len)
            return false;
        
        vector<int> original_hash(26,0);
        vector<int> hash(26,0);
        
        for(int i=0;i<k;i++)
        {
            original_hash[s1[i]-'a']++;
            hash[s2[i]-'a']++;
        }
        
        int left=0;
        int right=k-1;
        
        while(right<len)
        {
            if(original_hash==hash)
                return true;
            right++;
            if(right!=len)
                hash[s2[right]-'a']++;
            hash[s2[left]-'a']--;
            left++;
        }
        
        return false;
    }
};

