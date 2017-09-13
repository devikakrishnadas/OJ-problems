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

void bin(vi &a, ll b)
{
	int i=0;
	while(b)
	{
		a.pb(b%2);
		b=b/2;
		i++;
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ll l,r;
	cin>>l>>r;
	vi lb,rb;
	bin(lb,l);
	bin(rb,r);
	int n=rb.size();
	int tn=lb.size();
	for(int i=tn+1;i<=n;i++)
	{
		lb.pb(0);
	}
	reverse(all(lb));
	reverse(all(rb));
	ll cnt=1;
	bool enter=0;
	ll ans=0;
	for(int i=0;r;i++)
	{
		if(rb[i]==1 && lb[i]==0 && !enter)
		{
			enter=1;
		}
		if(enter)
		{
			ans=ans+cnt;
			cnt=cnt*2;
		}
		r=r/2;
		//cout<<r<<endl;
	}
	cout<<ans<<endl;
	return 0;
}

