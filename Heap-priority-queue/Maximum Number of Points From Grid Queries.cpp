// problem link --> https://leetcode.com/problems/maximum-number-of-points-from-grid-queries/description/

class Solution
{
public:
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};
    vector<int> maxPoints(vector<vector<int>> &grid, vector<int> &queries)
    {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        vector<pair<int, int>> vpr;
        for (int i = 0; i < queries.size(); i++)
            vpr.push_back({queries[i], i});
        sort(vpr.begin(), vpr.end());
        vector<int> ans(vpr.size(), 0);
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        pq.push({grid[0][0], 0, 0});
        vis[0][0] = true;
        int count = 0;
        for (int i = 0; i < vpr.size(); i++)
        {
            int value = vpr[i].first;
            int index = vpr[i].second;

            while ((!pq.empty()) && pq.top()[0] < value)
            {
                int x = pq.top()[1];
                int y = pq.top()[2];
                pq.pop();
                count++;
                for (int k = 0; k < 4; k++)
                {
                    int newX = x + dx[k];
                    int newY = y + dy[k];

                    if (newX >= 0 && newY >= 0 && newX < n && newY < m && !vis[newX][newY])
                    {
                        pq.push({grid[newX][newY], newX, newY});
                        vis[newX][newY] = true;
                    }
                }
            }
            ans[index] = count;
        }
        return ans;
    }
};