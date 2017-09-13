#include<bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define vc vector<char>
#define vll vector<ll>
#define pb push_back
#define sf scanf
#define ff first
#define M 1000000007
#define ss second
#define pf printf
#define mp make_pair
#define all(V) V.begin(),V.end()

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int n;
	vi a(100023),b(100012,0);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	b[1]=2;
	int ans=2;
	for(int i=2;i<=n;i++)
	{
		b[i]=2;
		for(int j=a[i];j<i;j++)
		{
			b[i]=(b[i]+b[j])%M;
		}
		ans=(ans+b[i])%M;
	}
	cout<<ans<<endl;
	return 0;
}

