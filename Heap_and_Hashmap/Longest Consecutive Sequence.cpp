// problem link -->  https://leetcode.com/problems/longest-consecutive-sequence/

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        map<int,int> mp;
        for(auto it:nums) mp[it]++;
        
        int ans=0,curr_len=0,prev=INT_MIN;
        
        for(auto it:mp)
        {
            if(it.first==prev+1){
                curr_len++;
            }else{
                curr_len=1;
            }
            prev=it.first;
            
            ans=max(ans,curr_len);
        }
        
        return ans;
    }
};