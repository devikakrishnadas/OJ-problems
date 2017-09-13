#include<bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define vc vector<char>
#define vll vector<ll>
#define MOD 1000000007
#define pb push_back
#define sf scanf
#define pf printf
#define mp make_pair
#define all(V) V.begin,V.end
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)

using namespace std;


int main()
{
	fast_io ;
	ll n,m;
	cin>>n>>m;
	//map<ll,ll>count[100023];
//	map<vector<int>,int> P;
	vector<vector<int> >cnt(m);// cnt[i] contains all the gym numbers who has the ith pokemon
	//vll A[100023];//contains the id of all pokemons who appears in same number of gyms;
	int k;
	int x;
	for(int i=0;i<n;i++)
	{
		cin>>k;
		for(int j=0;j<k;j++)
		{
			cin>>x;
			cnt[x-1].pb(i);
		}
	}
	/*for(int i=0;i<m;i++)
	{
		sort(cnt.begin(),cnt.end());
	}*/
	sort(cnt.begin(),cnt.end());
//	cout<<ma<<endl;
//	cout<<A[1].size()<<endl;
	//////////////////////////////////////////////////////////////////////////
//	int 
	// if pokemon i== pokemon j, then all the gyms that has i==all the gyms that has j;
	int count=1;
	ll ans=1;
	ll fact[1000023];
	fact[1]=1;
	fact[0]=1;
	for(ll i=2;i<=1000000;i++)
	{
		fact[i]=(fact[i-1]*i)%MOD;
	}
	for(int i=1;i<m;i++)
	{
		if(cnt[i]==cnt[i-1])
		{
			count++;
		}
		else
		{
			ans=(ans*fact[count])%MOD;
			count=1;
		}
	}
	ans=(ans*fact[count])%MOD;
	cout<<ans<<endl;
	return 0;
}

