#include <bits/stdc++.h>
#include <string>
#include <iostream>
#define PI 3.141592653589793
#define endl "\n"
#define INF 9000000000000000000
// #define INF 2e18
// #define max(a,b) (a>b?a:b)
// #define min(a,b) (a<b?a:b)
#define pb(a) push_back(a)
// #define pop() pop_back()
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
using namespace std;

class SGTree
{
    vector<int> seg;

public:
    SGTree(int n)
    {
        seg.resize(4 * n + 1);
    }
    void build(int idx, int low, int high, int arr[]) // 0-based indexing
    {
        if (low == high)
        {
            seg[idx] = arr[low];
            return;
        }
        int mid = (low + high) >> 1;
        build(2 * idx + 1, low, mid, arr);
        build(2 * idx + 2, mid + 1, high, arr);
        // post order work..
        seg[idx] = min(seg[2 * idx + 1], seg[2 * idx + 2]);
    }
    int query(int idx, int low, int high, int l, int r)
    {
        // Case-1 : No Overlap
        // [l r low high] OR [low high l r]
        if (high < l || r < low)
            return INT_MAX;

        // Case-2 : Complete Overlap
        // [l low high r]
        if (l <= low && high <= r)
            return seg[idx];

        // Case-3 : Partial Overlap
        int mid = (low + high) >> 1;
        int left = query(2 * idx + 1, low, mid, l, r);
        int right = query(2 * idx + 2, mid + 1, high, l, r);

        return min(left, right);
    }

    void update(int idx, int low, int high, int i, int val)
    {
        if (low == high)
        {
            seg[idx] = val;
            return;
        }
        int mid = (low + high) >> 1;
        if (i <= mid)
            update(2 * idx + 1, low, mid, i, val);
        else
            update(2 * idx + 2, mid + 1, high, i, val);
        seg[idx] = min(seg[2 * idx + 1], seg[2 * idx + 2]);
    }
};

void solve(int Tc) //(●'◡'●)
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    SGTree sg(n);
    sg.build(0, 0, n - 1, arr);

    int q;
    cin >> q;
    while (q--)
    {
        int type;
        cin >> type;
        if (type == 1)
        {
            int l, r;
            cin >> l >> r;
            cout << sg.query(0, 0, n - 1, l, r) << endl;
        }
        else
        {
            int i, val;
            cin >> i >> val;
            sg.update(0, 0, n - 1, i, val);
            arr[i] = val;
        }
    }
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("inputf.in", "r", stdin);
    freopen("outputf.out", "w", stdout);
    freopen("error.txt", "w", stderr);
#endif
    ll tc = 1;
    // cin >> tc;
    for (ll i = 1; i <= tc; i++)
    {
        solve(i);
    }
    return 0;
}