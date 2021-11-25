#include<bits/stdc++.h>
#include<iostream>
using namespace std;

int binarysearch(int arr[], int n, int key)
{
	int start=0;
	int end=n;
	while(start<=end)
	{
		int mid=(start+end)/2;
		if(arr[mid]==key)
			return mid;
		else if(arr[mid]<=key)
			start=mid+1;
		else
			end=mid-1;
	}
	return -1;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("inputf.in", "r", stdin);
	freopen("outputf.out", "w", stdout);
#endif
	int n;
	cin >> n;
	int arr[n];
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	int key;
	cin >> key;
	sort(arr, arr + n);
	cout << binarysearch(arr, n, key);
	return 0;
}

/*
input   5
		1 2 3 4 5
		4
output = 3
*/