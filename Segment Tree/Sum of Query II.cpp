// problem link --> https://practice.geeksforgeeks.org/problems/sum-of-query-ii5310/1

class Solution
{
public:
    vector<int> seg;
    void buildSeg(int idx, int low, int high, int arr[]) // 0-based indexing
    {
        if (low == high)
        {
            seg[idx] = arr[low];
            return;
        }
        int mid = (low + high) / 2;
        buildSeg(2 * idx + 1, low, mid, arr);
        buildSeg(2 * idx + 2, mid + 1, high, arr);
        // post order work..
        seg[idx] = seg[2 * idx + 1] + seg[2 * idx + 2];
    }
    int findRangeSum(int idx, int low, int high, int l, int r)
    {
        // Case-1 : No Overlap
        if (high < l || r < low)
            return 0;
        // Case-2 : Complete Overlap
        if (l <= low && high <= r)
            return seg[idx];
        // Case-3 : Partial Overlap

        int mid = (low + high) / 2;
        int left = findRangeSum(2 * idx + 1, low, mid, l, r);
        int right = findRangeSum(2 * idx + 2, mid + 1, high, l, r);

        return left + right;
    }
    vector<int> querySum(int n, int arr[], int q, int queries[])
    {
        seg = vector<int>(4 * n, 0);
        buildSeg(0, 0, n - 1, arr);

        vector<int> ans;

        for (int i = 0; i < 2 * q; i += 2)
        {
            ans.push_back(findRangeSum(0, 0, n - 1, queries[i] - 1, queries[i + 1] - 1));
        }

        return ans;
    }
};