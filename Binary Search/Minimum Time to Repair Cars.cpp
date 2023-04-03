// problem link --> https://leetcode.com/problems/minimum-time-to-repair-cars/

class Solution
{
public:
    bool isPossible(long long mid, vector<int> &nums, int cars)
    {
        int cnt = 0;
        for (auto it : nums)
        {
            cnt += (int)sqrt(mid / (1ll * it));
        }
        // cout<<cnt<<endl;
        return cnt >= cars;
    }
    long long repairCars(vector<int> &ranks, int cars)
    {
        int n = ranks.size();
        int temp = (cars % n == 0) ? (cars / n) : (cars / n + 1);

        long long l = 0ll;
        long long r = 0ll;
        for (int i = 0; i < n; i++)
        {
            r = max(r, 1ll * ranks[i] * temp * temp);
        }
        long long ans = r;
        while (l <= r)
        {
            long long mid = (r - l) / 2 + l;
            // cout<<mid<<"->"<<endl;
            if (isPossible(mid, ranks, cars))
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