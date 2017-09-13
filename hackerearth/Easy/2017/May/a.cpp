#include<bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define vc vector<char>
#define vll vector<ll>
#define pb push_back
#define sf scanf
#define pf printf
#define mp make_pair
#define all(V) V.begin(),V.end()

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n,x;
	cin>>n>>x;
	vi a(n);
	int ans=-1;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		x=x-a[i];
		if(x<0 && ans==-1)
		{
			ans=i;
		}
	}
	cout<<ans<<endl;

	return 0;
}

