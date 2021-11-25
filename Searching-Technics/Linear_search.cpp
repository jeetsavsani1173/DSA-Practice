#include<bits/stdc++.h>
#include<iostream>
using namespace std;

int linearsearch(int arr[],int n,int key)
{
	for(int i=0;i<n;i++)
	{
		if(arr[i]==key)
			return i;
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
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++)
		cin>>arr[i];
	int key;
	cin>>key;
	cout<<linearsearch(arr,n,key);
	return 0;
}

/*
input   5
		1 2 3 4 5
		4
output = 3
*/