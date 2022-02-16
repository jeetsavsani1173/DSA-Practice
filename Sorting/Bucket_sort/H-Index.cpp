// problem link -> https://leetcode.com/problems/h-index/

class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n=citations.size();
        vector<int> buckets(n+1,0);
        
        for(int i=0;i<n;i++)
        {
            if(citations[i]>n)
                buckets[n]++;
            else 
                buckets[citations[i]]++;
        }
        
        int total=0;
        
        for(int i=n;i>=0;i--)
        {
            total+=buckets[i];
            if(total>=i)
                return i;
        }
        
        return 0;
    }
};