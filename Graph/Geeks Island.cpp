// problem link --> https://practice.geeksforgeeks.org/problems/234ca3b438298fb04befd5abe7fbd98c006d4884/1

class Solution
{
public:
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};
    void dfs(int i, int j, vector<vector<int>> &mat, vector<vector<bool>> &vis)
    {
        vis[i][j] = true;
        for (int k = 0; k < 4; k++)
        {
            int newX = i + dx[k];
            int newY = j + dy[k];

            if (newX >= 0 && newY >= 0 && newX < mat.size() && newY < mat[0].size() && mat[newX][newY] >= mat[i][j] && !vis[newX][newY])
                dfs(newX, newY, mat, vis);
        }
    }
    int water_flow(vector<vector<int>> &mat, int N, int M)
    {
        vector<vector<bool>> vis1(N + 1, vector<bool>(M + 1, false));
        for (int i = 0; i < N; i++)
            if (!vis1[i][0])
                dfs(i, 0, mat, vis1);
        for (int j = 0; j < M; j++)
            if (!vis1[0][j])
                dfs(0, j, mat, vis1);

        vector<vector<bool>> vis2(N + 1, vector<bool>(M + 1, false));
        for (int i = 0; i < N; i++)
            if (!vis2[i][M - 1])
                dfs(i, M - 1, mat, vis2);
        for (int j = 0; j < M; j++)
            if (!vis2[N - 1][j])
                dfs(N - 1, j, mat, vis2);

        int ans = 0;
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++)
                if (vis1[i][j] && vis2[i][j])
                    ans++;

        return ans;
    }
};
