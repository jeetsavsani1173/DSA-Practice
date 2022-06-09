// problem link --> https://leetcode.com/problems/longest-repeating-character-replacement/

class Solution {
public:
    int characterReplacement(string s, int k) {
        int ans=INT_MIN;
        for(char ch='A';ch<='Z';ch++)
        {
            int left=0,count=0;
            for(int right=0;right<s.size();right++)
            {
                if(s[right]!=ch) count++;
                
                while(count>k){
                    if(s[left]!=ch) count--;
                    left++;
                }
                
                ans=max(ans,right-left+1);
            }
        }
        return ans;
    }
};