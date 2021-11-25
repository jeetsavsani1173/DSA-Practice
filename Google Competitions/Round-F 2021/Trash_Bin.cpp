#include<bits/stdc++.h>
#include<string>
#include<iostream>
#define PI  3.141592653589793
#define endl "\n"
#define ll long long
#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)
#define pb(a) push_back(a)
#define pop() pop_back()
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
// rep(i, 0, 10)  OUTPUT: 0 1 2 3 4 5 6 7 8 9 ;
using namespace std;

//---------- JEET SAVSANI ----------//

void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

int gcd(int a, int b)
{
	if (b == 0)
		return a;

	return gcd(b, a % b);
}

int fact(int n)
{
	if (n == 1)
		return 1;
	return n * fact(n - 1);

}

void reverse(int arr[], int n)
{
	int i = 0, j = n - 1;
	while (i < j)
	{
		int temp = arr[i];
		arr[i] = arr[j];
		arr[j] = temp;
		i++;  j--;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	ll tc = 1;
	cin >> tc;
	for(ll i=1;i<=tc;i++)
	{
		ll n;
		cin >> n;
		string s;
		cin >> s;

		ll arr[n];
		ll brr[n];

		ll j = -1;

		for (ll i = 0; i < s.size(); i++)
		{
			if (s[i] == '1')
				j = i;
			if (s[i] == '1')
				arr[i] = i;
			else
				arr[i] = j;
		}
		j = n;
		for (ll i = s.size() - 1; i >= 0; i--)
		{
			if (s[i] == '1')
				j = i;
			if (s[i] == '1')
				brr[i] = i;
			else
				brr[i] = j;
		}
		ll ans = 0;
		for (ll i = 0; i < n; i++)
		{
			if (arr[i] == -1)
				ans += (brr[i]-i);
			else if (brr[i] == n)
				ans += (i-arr[i]);
			else
				ans += min(i - arr[i], brr[i] - i);
		}


		cout <<"Case #"<<i<<": "<< ans << endl;


	}
	return 0;
}
	