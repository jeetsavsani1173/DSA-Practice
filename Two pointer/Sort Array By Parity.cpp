// problem link -->> https://leetcode.com/problems/sort-array-by-parity/

class Solution {
public:
    
    vector<int> sortArrayByParity(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n);
        int i = 0, j = n-1;
        
        for(int &x : nums) {
            if(x%2 == 0)  result[i++] = x;
            else          result[j--] = x;
        }
        return result;
    }
};