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
// #define M 1e9+7

void checkTimeout()
{
    double tm = (float)clock() / CLOCKS_PER_SEC;
    if (tm >= 2)
    {
        cerr << "Time limit exeeded" << endl;
        exit(0);
    }
}

typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;

//      _           _     ____                              _
//     | | ___  ___| |_  / ___|  __ ___   _____  __ _ _ __ (_)
//  _  | |/ _ \/ _ \ __| \___ \ / _` \ \ / / __|/ _` | '_ \| |
// | |_| |  __/  __/ |_   ___) | (_| |\ V /\__ \ (_| | | | | |
//  \___/ \___|\___|\__| |____/ \__,_| \_/ |___/\__,_|_| |_|_|

// Operator overloads <<, >>
template <typename T1, typename T2>
istream &operator>>(istream &istream, pair<T1, T2> &p)
{
    return (istream >> p.first >> p.second);
} // cin >> pair<T1, T2>
template <typename T>
istream &operator>>(istream &istream, vector<T> &v)
{
    for (auto &it : v)
    {
        cin >> it;
    }
    return istream;
} // cin >> vector<T>
template <typename T1, typename T2>
ostream &operator<<(ostream &ostream, const pair<T1, T2> &p)
{
    return (ostream << p.first << " " << p.second);
} // cout << pair<T1, T2>
template <typename T>
ostream &operator<<(ostream &ostream, const vector<T> &c)
{
    for (auto &it : c)
    {
        cout << it << " ";
    }
    return ostream;
} // cout << vector<T>

#ifndef ONLINE_JUDGE
#define debug(x)       \
    cerr << #x << " "; \
    _print(x);         \
    cerr << endl;
#else
#define debug(x)
#endif

void _print(ll t)
{
    cerr << t;
}
void _print(int t) { cerr << t; }
void _print(string t) { cerr << t; }
void _print(char t) { cerr << t; }
void _print(lld t) { cerr << t; }
void _print(double t) { cerr << t; }
void _print(ull t) { cerr << t; }

template <class T>
bool ckmin(T &a, const T &b) { return b < a ? a = b, 1 : 0; }
template <class T>
bool ckmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }

template <class T, class V>
void _print(pair<T, V> p);
template <class T>
void _print(vector<T> v);
template <class T>
void _print(set<T> v);
template <class T, class V>
void _print(map<T, V> v);
template <class T>
void _print(multiset<T> v);
template <class T, class V>
void _print(pair<T, V> p)
{
    cerr << "{";
    _print(p.first);
    cerr << ",";
    _print(p.second);
    cerr << "}";
}
template <class T>
void _print(vector<T> v)
{
    cerr << "[ ";
    for (T i : v)
    {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}
template <class T>
void _print(set<T> v)
{
    cerr << "[ ";
    for (T i : v)
    {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}
template <class T>
void _print(multiset<T> v)
{
    cerr << "[ ";
    for (T i : v)
    {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}
template <class T, class V>
void _print(map<T, V> v)
{
    cerr << "[ ";
    for (auto i : v)
    {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}

// 8-dimension point
int dx8[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dy8[8] = {0, 1, 1, 1, 0, -1, -1, -1};

// 4-dimension point
int dx4[4] = {-1, 0, 1, 0};
int dy4[4] = {0, 1, 0, -1};

// Knight move point
int knightx[8] = {-2, -1, +1, +2, +2, +1, -1, -2};
int knighty[8] = {+1, +2, +2, +1, -1, -2, -2, -1};

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

class DisjointSet
{
    vector<int> rank, parent, size;

public:
    DisjointSet(int n)
    {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n + 1, 1);
        for (int i = 0; i <= n; i++)
            parent[i] = i;
    }

    // find Ultimate Parent with path compression..
    int findUPar(int node)
    {
        if (node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]);
    }

    // Union by Rank..
    void unionByRank(int u, int v)
    {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);

        if (ulp_u == ulp_v)
            return;
        if (rank[ulp_u] < rank[ulp_v])
        {
            parent[ulp_u] = ulp_v;
        }
        else if (rank[ulp_u] > rank[ulp_v])
        {
            parent[ulp_v] = ulp_u;
        }
        else
        {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }

    // Union by Size
    void unionBySize(int u, int v)
    {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);

        if (ulp_u == ulp_v)
            return;
        if (size[ulp_u] < size[ulp_v])
        {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else
        {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};

template <typename T>
void swap(T *a, T *b)
{
    T temp = *a;
    *a = *b;
    *b = temp;
}

bool isprime(long long n)
{
    if (n < 2)
        return false;
    if (n == 2 || n == 3)
        return true;
    if (n % 2 == 0 || n % 3 == 0)
        return false;

    for (long long i = 6L; i <= sqrt(n); i += 6)
    {
        if (n % (i - 1) == 0 || n % (i + 1) == 0)
            return false;
    }
    return true;
}

ll M = 1e9 + 7;

ll modPow(ll n, ll x)
{
    if (x == 0)
        return 1ll;

    ll pow = modPow(n, x / 2);

    if (x % 2 == 0)
        return ((pow % M) * (pow % M)) % M;
    else
        return ((((n % M) * (pow % M)) % M) * pow % M) % M;
}

vector<bool> seive(int n)
{
    vector<bool> is_prime(n + 1, true);
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i * i <= n; i++)
    {
        if (is_prime[i])
        {
            for (int j = i * i; j <= n; j += i)
                is_prime[j] = false;
        }
    }
    return is_prime;
}

bool is_squre(ll n)
{
    if ((sqrt(n) * sqrt(n) * 1ll) == n)
        return true;
    else
        return false;
}

void prime_factorization(int n, vector<pair<int, int>> &ans)
{
    // vector<pair<int, int>> ans;
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            int cnt = 0;
            while (n % i == 0)
            {
                n /= i;
                cnt++;
            }
            ans.push_back({i, cnt});
        }
    }
    if (n != 1)
        ans.push_back({n, 1});
}

ll kadanes_algo(vector<ll> &v)
{
    ll mx = 0;
    ll sum = 0;
    for (ll i = 0; i < v.size(); i++)
    {
        sum += v[i];
        mx = max(mx, sum);
        if (sum < 0)
            sum = 0;
    }
    return mx;
}

void solve(int Tc) //(●'◡'●)
{
    DisjointSet ds(7);

    ds.unionBySize(1, 2);
    ds.unionBySize(2, 3);
    ds.unionBySize(4, 5);
    ds.unionBySize(6, 7);
    ds.unionBySize(5, 6);
    // if 3 and 7 same or not..
    if (ds.findUPar(3) == ds.findUPar(7))
    {
        cout << "Same" << endl;
    }
    else
    {
        cout << "Not Same" << endl;
    }

    ds.unionBySize(3, 7);

    if (ds.findUPar(3) == ds.findUPar(7))
    {
        cout << "Same" << endl;
    }
    else
    {
        cout << "Not Same" << endl;
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