// problem link -->  https://leetcode.com/problems/find-k-closest-elements/

class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        vector<int> ans;
        int second=lower_bound(arr.begin(),arr.end(),x)-arr.begin();
        int first=second-1;
        
        while(k && first>=0 && second<arr.size())
        {
            if(abs(x-arr[second])>=abs(x-arr[first]))
            {
                ans.push_back(arr[first]);
                first--;
            }
            else
            {
                ans.push_back(arr[second]);
                second++;
            }
            k--;
        }
        while(k && first>=0)
        {
            ans.push_back(arr[first]);
            first--;
            k--;
        }
        while(k && second<arr.size())
        {
            ans.push_back(arr[second]);
            second++;
            k--;
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
    
};