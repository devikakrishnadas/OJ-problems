#include<bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define vc vector<char>
#define vll vector<ll>
#define pb push_back
#define sf scanf
#define pf printf
#define mp make_pair
#define M 1000000007
#define all(V) V.begin(),V.end()

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	vi a(5),b(5);
	int ans=0;
	for(int i=0;i<5;i++)
	{
		cin>>a[i];
		ans+=a[i];
	}
	for(int j=0;j<5;j++)
	{
		cin>>b[j];
	}
	
	return 0;
}

