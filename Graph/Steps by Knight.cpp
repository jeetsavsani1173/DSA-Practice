// problem link --> https://practice.geeksforgeeks.org/problems/steps-by-knight5927/1

class Solution
{
    int knightx[8] = {-2, -1, +1, +2, +2, +1, -1, -2};
    int knighty[8] = {+1, +2, +2, +1, -1, -2, -2, -1};

public:
    bool isValid(int x, int y, int n, int m)
    {
        return (x >= 0 && x < n && y >= 0 && y < m);
    }
    // Function to find out minimum steps Knight needs to reach target position.
    int minStepToReachTarget(vector<int> &src, vector<int> &dest, int n)
    {
        vector<vector<int>> ans(n, vector<int>(n, -1));

        queue<vector<int>> q;
        q.push({src[0] - 1, src[1] - 1, 0});

        while (!q.empty())
        {
            int x = q.front()[0];
            int y = q.front()[1];
            int dis = q.front()[2];
            q.pop();
            if (ans[x][y] != -1)
                continue;
            ans[x][y] = dis;
            for (int k = 0; k < 8; k++)
            {
                int newX = x + knightx[k];
                int newY = y + knighty[k];

                if (isValid(newX, newY, n, n) && ans[newX][newY] == -1)
                {
                    q.push({newX, newY, dis + 1});
                }
            }
        }
        return ans[dest[0] - 1][dest[1] - 1];
    }
};