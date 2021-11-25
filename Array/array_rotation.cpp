#include<bits/stdc++.h>
#include<iostream>
using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("inputf.in", "r", stdin);
	freopen("outputf.out", "w", stdout);
#endif
	int n, a;
	cin >> n >> a;
	int array[n + a] = {0};
	for (int i = 0; i < n; i++)
		cin >> array[i];
	for (int i = 0; i < a; i++)
	{
		array[n + i] = array[i];
	}
	for (int i = a; i < n + a; i++)
	{
		array[i - a] = array[i];
	}
	for (int i = 0; i < n; i++)
		cout << array[i] << " ";
	return 0;
}

/*input:- 7 2
		  1 2 3 4 5 6 7
output:- 3 4 5 6 7 1 2
*/