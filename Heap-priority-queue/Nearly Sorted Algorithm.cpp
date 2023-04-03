// problem link --> https://practice.geeksforgeeks.org/problems/nearly-sorted-algorithm/0

#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        vector<int> arr(n, 0);
        for (int i = 0; i < n; i++)
            cin >> arr[i];

        priority_queue<int, vector<int>, greater<int>> pq;
        int i = 0;
        for (i = 0; i < k; i++)
            pq.push(arr[i]);

        int idx = 0;
        while (i < n)
        {
            arr[idx++] = pq.top();
            pq.pop();
            pq.push(arr[i++]);
        }

        while (idx < n)
        {
            arr[idx++] = pq.top();
            pq.pop();
        }

        for (int i = 0; i < n; i++)
            cout << arr[i] << " ";
        cout << endl;
    }
    return 0;
}