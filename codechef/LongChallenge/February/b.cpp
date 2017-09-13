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
	ll n,l,r;
	cin>>n>>l>>r;
	vll A(n);
	vector<pair<ll,ll> >M;
	for(int i=0;i<n;i++)
	{
		cin>>A[i];
	}
	sort(A.begin(),A.begin()+n);
	for(int i=1;i<n;i++)
	{
		ll a=A[i]+A[i-1]-1;
		ll b=A[i]-A[i-1]+1;
		//if(ma[i-1]>r)ma[i-1]=r;
		//if(mi[i-1]<l) mi[i]=l;
		if(a<l) continue;
		if(b>r) continue;
		if(a>r) a=r;
                if(b<l) b=l;
		//ma.pb(a);
		//mi.pb(b);
		M.pb(mp(b,a));
	}
	sort(M.begin(),M.end());
	ll ans=0;
	ll u=M[0].first;
	ll v=M[0].second;
	for(int i=1;i<M.size();i++)
	{
		if(M[i].second<=v) continue;
		if(M[i].first<=v)
		{
			//ans=ans+(M[i].second-v);
			v=M[i].second;
		}
		else
		{
			ans=ans+v-u+1;
			//ans=ans+M[i].second-M[i].first+1;
			u=M[i].first;
			v=M[i].second;
		}
	}
	ans=ans+v-u+1;
	cout<<ans<<endl;
	return 0;
}

