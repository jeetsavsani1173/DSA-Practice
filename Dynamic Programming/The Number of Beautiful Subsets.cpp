// problem link --> https://leetcode.com/contest/weekly-contest-337/problems/the-number-of-beautiful-subsets/

class Solution
{
public:
    int ans;
    int check(vector<int> &taken, int k)
    {
        sort(taken.begin(), taken.end());
        for (int i = 0; i < taken.size(); i++)
        {
            for (int j = 0; j < taken.size(); j++)
            {
                if ((taken[j] - taken[i]) == k)
                    return 0;
            }
        }
        return 1;
    }
    void helper(int idx, vector<int> &nums, int k, unordered_map<int, int> &mp)
    {
        if (idx == nums.size())
        {
            ans++;
            return;
        }

        // Take
        if (mp[nums[idx] - k] == 0 && mp[nums[idx] + k] == 0)
        {
            mp[nums[idx]]++;
            helper(idx + 1, nums, k, mp);
            mp[nums[idx]]--;
        }

        // Non-Take
        helper(idx + 1, nums, k, mp);
    }
    int beautifulSubsets(vector<int> &nums, int k)
    {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        ans = 0;
        unordered_map<int, int> mp;
        helper(0, nums, k, mp);
        return ans - 1;
    }
};