// problem link --> https://leetcode.com/problems/minimize-maximum-of-array/

class Solution
{
public:
    bool isPossible(int key, vector<long long> nums)
    {
        for (int i = nums.size() - 1; i > 0; i--)
        {
            if (nums[i] > key)
            {
                nums[i - 1] += (nums[i] - key);
                nums[i] = key;
            }
        }
        return (nums[0] <= key);
    }
    int minimizeArrayValue(vector<int> &nums)
    {
        int l = 0;
        int r = *max_element(nums.begin(), nums.end());
        int ans = r;
        vector<long long> temp;
        for (auto it : nums)
            temp.push_back(1ll * it);
        while (l <= r)
        {
            int mid = (r - l) / 2 + l;
            if (isPossible(mid, temp))
            {
                ans = mid;
                r = mid - 1;
            }
            else
            {
                l = mid + 1;
            }
        }
        return ans;
    }
};