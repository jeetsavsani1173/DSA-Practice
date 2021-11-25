problem link -->> https://codeforces.com/problemset/problem/189/A

#include<bits/stdc++.h>
#include<string>
#include<iostream>
#define PI  3.141592653589793
#define endl "\n"
#define ll long long
#define INF 9000000000000000000
// #define max(a,b) (a>b?a:b)
// #define min(a,b) (a<b?a:b)
#define pb(a) push_back(a)
// #define pop() pop_back()
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
// rep(i, 0, 10)  OUTPUT: 0 1 2 3 4 5 6 7 8 9 ;
using namespace std;
#define M 1000000007

//---------- JEET SAVSANI ----------//

// Operator overloads <<, >>
template<typename T1, typename T2>
istream &operator>>(istream &istream, pair<T1, T2> &p) {
    return (istream >> p.first >> p.second);
} // cin >> pair<T1, T2>
template<typename T>
istream &operator>>(istream &istream, vector<T> &v) {
    for (auto &it : v) {
        cin >> it;
    }
    return istream;
} // cin >> vector<T>
template<typename T1, typename T2>
ostream &operator<<(ostream &ostream, const pair<T1, T2> &p) {
    return (ostream << p.first << " " << p.second);
} // cout << pair<T1, T2>
template<typename T>
ostream &operator<<(ostream &ostream, const vector<T> &c) {
    for (auto &it : c) {
        cout << it << " ";
    }
    return ostream;
} // cout << vector<T>

template<typename T>
void swap(T *a, T *b)
{
    T temp = *a;
    *a = *b;
    *b = temp;
}

bool isprime(long n)
{
    if (n < 2) return false;
    if (n == 2 || n == 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;

    for (long i = 6L; i <= sqrt(n); i += 6) {
        if (n % (i - 1) == 0 || n % (i + 1) == 0) return false;
    }
    return true;
}

vector<int> digitTovec(int n)
{
    vector<int> ans;
    while (n)
    {
        ans.pb(n % 10);
        n /= 10;
    }

    return ans;
}

bool comp(int a, int b)
{
    return a > b;
}

int sum(int n)
{
    int ans = 0;
    while (n)
    {
        ans += (n % 10);
        n /= 10;
    }
    return ans;
}

int dp[10005];

int recursion_func(int n, int a, int b, int c)
{
    if (n == 0)
        return 0;

    if (dp[n] != -1)
        return dp[n];

    int op1 = INT_MIN, op2 = INT_MIN, op3 = INT_MIN;
    if (n >= a) op1 = recursion_func(n - a, a, b, c);
    if (n >= b) op2 = recursion_func(n - b, a, b, c);
    if (n >= c) op3 = recursion_func(n - c, a, b, c);

    dp[n] = 1 + max(op1, max(op2, op3));
    return dp[n];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("inputf.in", "r", stdin);
    freopen("outputf.out", "w", stdout);
#endif
    ll tc = 1;
    // cin >> tc;
    while (tc--)
    {
        int n, a, b, c;
        cin >> n >> a >> b >> c;
        memset(dp, -1, sizeof(dp));
        int ans = recursion_func(n, a, b, c);
        if (ans < 0)
            cout << "0" << endl;
        else
            cout << ans << endl;
    }
    return 0;
}
