// problem link --> https://practice.geeksforgeeks.org/problems/range-minimum-query/1

int seg[5000];
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
    seg[idx] = min(seg[2 * idx + 1], seg[2 * idx + 2]);
}
int *constructST(int arr[], int n)
{
    buildSeg(0, 0, n - 1, arr);
    return seg;
}

int findRangeMin(int idx, int low, int high, int l, int r, int sgt[])
{
    // Case-1 : No Overlap
    if (high < l || r < low)
        return INT_MAX;
    // Case-2 : Complete Overlap
    if (l <= low && high <= r)
        return sgt[idx];
    // Case-3 : Partial Overlap

    int mid = (low + high) / 2;
    int left = findRangeMin(2 * idx + 1, low, mid, l, r, sgt);
    int right = findRangeMin(2 * idx + 2, mid + 1, high, l, r, sgt);

    return min(left, right);
}
/* The functions returns the
 min element in the range
 from a and b */
int RMQ(int st[], int n, int a, int b)
{
    return findRangeMin(0, 0, n - 1, a, b, st);
}