// problem link -> https://leetcode.com/problems/longest-substring-without-repeating-characters/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char,int> mp;
        int left=0,maxLen=INT_MIN;
        for(int right=0;right<s.size();right++)
        {
            if(mp[s[right]]==1)
            {
                mp[s[right]]++;
                while(mp[s[right]]>1){
                    mp[s[left]]--;
                    left++;
                }
            }else{
                mp[s[right]]++;
            }
            maxLen=max(maxLen,right-left+1);
        }
        
        return maxLen==INT_MIN?0:maxLen;
    }
};