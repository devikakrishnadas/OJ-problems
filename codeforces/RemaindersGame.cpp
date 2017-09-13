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

vi prime(1000001,1);
vi pp;
void sieve()
{
	for(int i=2;i<=10001;i++)
	{
		if(prime[i])
		{
			for(int j=2;i*j<=10001;j++)
			{
				prime[i*j]=0;
			}
			pp.pb(i);
		}
	}
}
void primeFactors(int a,vi &b)
{
	for(int i=0;pp[i]<=sqrt(a);i++)
	{
		int cnt=0;
		while(a%pp[i]==0)
		{
			a=a/pp[i];
			cnt++;
		}
		b[pp[i]]=max(b[pp[i]],cnt);
	}
	if(a>1)
	{
		b[a]=max(b[a],1);
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	sieve();
	ll n,k;
	cin>>n>>k;
	vi a(n);
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	sort(all(a));
	vi lcm(1000001,0);
	vi pfk(1000001,0);
	primeFactors(k,pfk);
	for(int i=0;i<n;i++)
	{
		if(i) if(a[i]==a[i-1]) continue;
		primeFactors(a[i],lcm);
	}
	//primeFactors(k,pfk);
	bool no=0;
	//cout<<pfk[2]<<" "<<pfs[2]<<" "<<gcd[2]<<endl;
	
	for(int i=2;i<=k;i++)
	{
		pfk[i]=max(0,pfk[i]-lcm[i]);
		if(pfk[i]) 
		{
			no=1;
		}
	}
	if(no)
		cout<<"No"<<endl;
	else
		cout<<"Yes"<<endl;
	return 0;
}
