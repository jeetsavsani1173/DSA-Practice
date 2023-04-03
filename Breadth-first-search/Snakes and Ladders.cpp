// probelm link --> https://leetcode.com/problems/snakes-and-ladders/

class Solution
{
public:
    pair<int, int> find_cordinate(int temp, int n)
    {
        int row = n - (temp - 1) / n - 1;
        int col = ((temp - 1) % n);
        if (n % 2 == row % 2)
        {
            col = n - 1 - col;
        }
        return {row, col};
    }
    int snakesAndLadders(vector<vector<int>> &board)
    {
        int n = board.size();
        vector<vector<bool>> vis(n, vector<bool>(n, false));
        queue<pair<int, int>> q;
        q.push({1, 0});

        while (!q.empty())
        {
            pair<int, int> x = q.front();
            q.pop();
            if (x.first == n * n)
                return x.second;

            for (int k = 1; k <= 6; k++)
            {
                if ((k + x.first) > n * n)
                    break;
                pair<int, int> newP = find_cordinate(k + x.first, n);
                if (vis[newP.first][newP.second] == true)
                    continue;
                vis[newP.first][newP.second] = true;
                if (board[newP.first][newP.second] != -1)
                    q.push({board[newP.first][newP.second], x.second + 1});
                else
                    q.push({x.first + k, x.second + 1});
            }
        }

        return -1;
    }
};