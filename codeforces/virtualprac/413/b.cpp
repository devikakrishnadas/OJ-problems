#include<bits/stdc++.h>
#define ll long
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
	vector<pair<ll,pair<ll,ll> > >A;
	ll p[200023],a[200023],b[200032];
	ll pointer[4]={0};
	
	ll m;
	vi c(200023);
	ll n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>p[i];
	}
	for(int i=0;i<n;i++)
		cin>>a[i];
	for(int i=0;i<n;i++)
	{
		cin>>b[i];
		A.pb(mp(p[i],mp(a[i],b[i])));
	}
	cin>>m;
	sort(all(A));
	for(int i=0;i<m;i++)
	{
		cin>>c[i];
		int enter=0;
		for(int j=pointer[c[i]];j<n;j++)
		{
			if((A[j].ss.ff==c[i] || A[j].ss.ss==c[i]) && A[j].ff != -1)
			{
				pointer[c[i]]=j+1;
				cout<<A[j].ff<<" ";
				A[j].ff=-1;
				enter=1;
				break;
			}
		}
		if(!enter)
		{
			cout<<-1<<" ";
			pointer[c[i]]=n;
		}
	}
	cout<<endl;
	return 0;
}

