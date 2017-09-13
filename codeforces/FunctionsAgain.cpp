#include<bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define vc vector<char>
#define vll vector<ll>
#define pb push_back
#define sf scanf
#define pf printf
#define mp make_pair
#define all(V) V.begin,V.end

using namespace std;

int main()
{
	int n;
	cin>>n;
	vi a(n);
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	vi b;
	for(int i=1;i<n;i++)
	{
		b.pb(abs(a[i]-a[i-1]));
	}
	int j=1;
	int ans=INT_MIN;
	for(int i=0;i<b.size();i++)
	{
		if(a[j]<=a[i])
		{
			ans=max(ans,a[i]-a[j]);
			j++;
		}
		else
		{
			while(
		}
	}
	return 0;
}
