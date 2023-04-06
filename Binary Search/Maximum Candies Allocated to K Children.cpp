// problem link --> https://leetcode.com/problems/maximum-candies-allocated-to-k-children/

class Solution
{
public:
    bool isPossible(vector<int> &candies, long long mid, long long k)
    {
        long long temp = 0;
        for (auto it : candies)
        {
            temp += ((1ll * it) / mid);
            if (temp >= k)
                return true;
        }
        return false;
    }
    int maximumCandies(vector<int> &candies, long long k)
    {
        long long l = 1ll;
        long long r = *max_element(candies.begin(), candies.end());
        int ans = 0;
        while (l <= r)
        {
            long long mid = (r - l) / 2 + l;
            if (isPossible(candies, mid, k))
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
};