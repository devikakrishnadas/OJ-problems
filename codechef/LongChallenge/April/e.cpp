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

vi p;
vi a(1000001,3);
void sieve()
{
	//bool a[1000001]={0};
	for(int i=2;i<=1000000;i++)
	{
		if(a[i])
		{
			p.pb(i);
			for(int j=2;i*j<=1000000;j++)
			{
				a[i*j]=0;
			}
		}
		
	}
	a[1]=0;
	
}

ll PT( ll b)
{
	
	
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ll A,b;
	cin>>A>>b;
	ll ans=0;
	sieve();
	//cout<<p.size()<<endl;
	for(ll i=b;i>=A;i--)
	{
		ans=ans + PT(i)-1;
	}	
	cout<<ans<<endl;
	return 0;
}
