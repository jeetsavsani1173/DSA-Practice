// problem link --> https://leetcode.com/problems/binary-search/

class Solution {
public:
    int Binary_search(int i,int j,vector<int> &num,int target)
    {
        if(i<=j)
        {
            int mid=i+(j-i)/2;
            if(num[mid]==target)
                return mid;
            else if(num[mid]>target)
                return Binary_search(i,mid-1,num,target);
            else
                return Binary_search(mid+1,j,num,target);
        }
        
        return -1;
    }
    int search(vector<int>& nums, int target) {
        return Binary_search(0,nums.size()-1,nums,target);
    }
};