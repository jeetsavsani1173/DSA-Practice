// problem link -->> https://leetcode.com/problems/rotate-array/

class Solution {
public:
    void rev(vector<int> &v,int i,int j)
    {
        while(i<j)
        {
            int temp;
            temp=v[i];
            v[i]=v[j];
            v[j]=temp;
            i++;
            j--;
        }
    }
    
    void rotate(vector<int>& nums, int k) {
        k = k % nums.size();
        if(k < 0)
            k += nums.size();
        
        rev(nums,0,nums.size()-k-1);
        rev(nums,nums.size()-k,nums.size()-1);
        rev(nums,0,nums.size()-1);
    }
};