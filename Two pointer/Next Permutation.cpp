// problem link --> https://leetcode.com/problems/next-permutation/

class Solution
{
public:
    void nextPermutation(vector<int> &nums)
    {
        if (nums.size() == 1)
            return;
        int idx = -1;

        for (int i = nums.size() - 2; i >= 0; i--)
        {
            if (nums[i] < nums[i + 1])
            {
                idx = i;
                break;
            }
        }

        if (idx == -1)
        {
            reverse(nums.begin(), nums.end());
            return;
        }
        int idx1 = -1;
        for (int i = nums.size() - 1; i >= 0; i--)
        {
            if (nums[i] > nums[idx])
            {
                idx1 = i;
                break;
            }
        }

        swap(nums[idx], nums[idx1]);

        int i = idx + 1, j = nums.size() - 1;
        while (i < j)
        {
            swap(nums[i++], nums[j--]);
        }
    }
};