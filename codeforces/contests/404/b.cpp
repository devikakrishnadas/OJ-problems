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
	ll n;
	vector<pair<ll,ll> >A,B,C,D;
	cin>>n;	
	ll m,x,y;
	for(int i=0;i<n;i++)
	{
		cin>>x>>y;
		A.pb(mp(x,y));
		C.pb(mp(y,x));
	}
	sort(all(A));
	cin>>m;
	for(int i=0;i<m;i++)
	{
		cin>>x>>y;
		B.pb(mp(x,y));
		D.pb(mp(y,x));
	}
	sort(all(B));
	sort(all(C));
	sort(all(D));
	ll start1A,aa,start1B,bb;
	start1A=A[n-1].first;
	start1B=B[m-1].first;
	aa=C[0].first;
	bb=D[0].first;
	ll ans=max(start1A-bb,start1B-aa);
	if(ans<0) ans=0;
	cout<<ans<<endl;
	
	
	return 0;
}

