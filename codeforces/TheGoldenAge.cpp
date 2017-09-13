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
	ll x,y,l,r;
	cin>>x>>y>>l>>r;
	vll xa,ya;
	ll xt=1;
	//cout<<"r0"<<endl;
	while(xt<=(1000000000000000000) )
	{
		xa.pb(xt);
		if(xt>LLONG_MAX/x)
			break;
		xt*=x;
//		if(xt)
//		cout<<xt<<" "<<x<<endl;
	}
	//cout<<"r1"<<endl;
	ll yt=1;
	while(yt<=(1000000000000000000))
	{
		ya.pb(yt);
		if(yt>LLONG_MAX/y)
			break;
		yt*=y;
	}
//	cout<<"r2"<<endl;
	//cout<<xa.size()<<" "<<ya.size()<<endl;
	vll ans;
	for(int i=0;i<xa.size();i++)
	{
		for(int j=0;j<ya.size();j++)
		{
			ll t=xa[i]+ya[j];
			if(t>=l && t<=r)
			{
//				cout<<"this is t"<<endl;
				//cout<<t<<endl;
				ans.pb(t);
			}
		}
	}
	//cout<<"r3"<<endl;
	if(ans.size()==0)
	{
		cout<<r-l+1<<endl;
		return 0;
	}
	ans.pb(r+1);
	ans.pb(l-1);
	sort(all(ans));
	ll val=0;
//	cout<<"size "<<ans.size()<<endl;
	for(int i=1;i<ans.size();i++)
	{
		if(ans[i]-ans[i-1]-1>val)
		{
			val=ans[i]-ans[i-1]-1;
//			cout<<val<<" = "<<ans[i]<<" - "<<ans[i-1]<<endl;
		}
	}
	if(val<0) val=0;
	cout<<val<<endl;
	return 0;
}

