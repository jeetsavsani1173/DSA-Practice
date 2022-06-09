// problem link --> https://leetcode.com/problems/tuple-with-same-product/

class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        int n=nums.size();
        map<int,int> mp;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                mp[nums[i]*nums[j]]++;
            }
        }
        
        int ans=0;
        for(auto it:mp)
        {
            int freq=it.second;
            ans+=(freq*(freq-1)/2);
        }
        return 8*ans;
    }
};