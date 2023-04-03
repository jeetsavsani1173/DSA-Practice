// problem link --> https://leetcode.com/problems/minimum-operations-to-make-all-array-elements-equal/

class Solution
{
public:
    int my_bound(vector<int> &nums, int temp)
    {
        int l = 0, r = nums.size() - 1;
        int ans = 0;
        while (l <= r)
        {
            int mid = (l + r) / 2;
            if (nums[mid] <= temp)
            {
                ans = mid;
                l = mid + 1;
            }
            else
            {
                r = mid - 1;
            }
        }
        return ans;
    }
    vector<long long> minOperations(vector<int> &nums, vector<int> &queries)
    {
        long long n = nums.size();
        sort(nums.begin(), nums.end());
        vector<long long> pref(n, 0ll);
        pref[0] = (nums[0]);
        for (int i = 1; i < n; i++)
        {
            pref[i] = (pref[i - 1] + 1ll * nums[i]);
        }
        vector<long long> ans(queries.size(), 0);

        for (int i = 0; i < queries.size(); i++)
        {
            long long it = queries[i];
            long long index = (lower_bound(nums.begin(), nums.end(), it) - nums.begin());
            // index--;
            long long temp_ans = 0ll;
            temp_ans = temp_ans + (it * (index) - ((index > 0) ? pref[index - 1] : 0));
            temp_ans = temp_ans + ((pref[n - 1] - ((index > 0) ? pref[index - 1] : 0)) - it * (n - index));
            ans[i] = (temp_ans);
        }
        return ans;
    }
};