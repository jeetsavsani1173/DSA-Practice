// problem link --> https://leetcode.com/problems/daily-temperatures/description/

class Solution
{
public:
    vector<int> find_NGE(vector<int> &nums)
    {
        vector<int> ans(nums.size(), -1);

        stack<int> stk;

        stk.push(nums.size() - 1);

        for (int i = nums.size() - 2; i >= 0; i--)
        {
            while ((!stk.empty()) && nums[i] >= nums[stk.top()])
            {
                stk.pop();
            }

            if (!stk.empty())
                ans[i] = stk.top();
            stk.push(i);
        }

        return ans;
    }
    vector<int> dailyTemperatures(vector<int> &temperatures)
    {
        vector<int> nge = find_NGE(temperatures);

        for (int i = 0; i < nge.size(); i++)
        {
            if (nge[i] == -1)
                nge[i] = 0;
            else
                nge[i] -= i;
        }
        return nge;
    }
};