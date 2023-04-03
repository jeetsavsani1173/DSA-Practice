// problem link --> https://leetcode.com/problems/ipo/

class Solution
{
public:
    int findMaximizedCapital(int k, int w, vector<int> &profits, vector<int> &capital)
    {
        priority_queue<pair<int, int>> mx;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> mn;

        for (int i = 0; i < capital.size(); i++)
            mn.push({capital[i], i});

        int avaCap = w;
        for (int i = 0; i < k; i++)
        {
            while (!mn.empty() && mn.top().first <= avaCap)
            {
                int idx = mn.top().second;
                mx.push({profits[idx], idx});
                mn.pop();
            }
            if (mx.empty())
                break;
            avaCap += mx.top().first;
            mx.pop();
        }

        return avaCap;
    }
};