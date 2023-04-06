// problem link --> https://practice.geeksforgeeks.org/problems/k-sum-paths/1

class Solution
{
public:
    int M = 1e9 + 7;
    void dfs(Node *root, int k, int sum, unordered_map<int, int> &mp, int &ans)
    {
        if (root == NULL)
            return;

        if (root->data + sum == k)
            ans++;

        ans = (ans % M + mp[sum + root->data - k] % M) % M;

        mp[sum + root->data]++;
        dfs(root->left, k, sum + root->data, mp, ans);
        dfs(root->right, k, sum + root->data, mp, ans);
        mp[sum + root->data]--;
    }
    int sumK(Node *root, int k)
    {
        unordered_map<int, int> mp;
        int ans = 0;
        dfs(root, k, 0, mp, ans);
        return ans;
    }
};