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
ll ans=LLONG_MIN;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ll n,m,k,p;
	cin>>n>>m>>k>>p;
	ll rowsum[1002]={0},colsum[1002]={0};
	ll a;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			cin>>a;
			rowsum[i]+=a;
			colsum[j]+=a;
		}
	}
	priority_queue<ll>rows,cols,row1;
	priority_queue<ll,vector<ll>,greater<ll> >col1;
	vll row,col;
	for(int i=0;i<n;i++)
	{
		rows.push(rowsum[i]);
	}
	for(int i=0;i<m;i++)
	{
		cols.push(colsum[i]);
	}
	ll sum=0;
	ll i=k;
	row.pb(0);
	while(i--)
	{
		ll a=rows.top();
		sum+=a;
		row.pb(sum);
		rows.pop();
		rows.push(a-m*p);
	}
	i=k;
	sum=0;
	col.pb(0);
	while(i--)
	{
		ll a=cols.top();
		sum+=a;
		col.pb(sum);
		cols.pop();
		cols.push(a-n*p);
	}
	
	for(int i=0;i<=k;i++)
	{
		ll a=row[k-i];
		ll b=col[i];
		ans=max(ans,a+b-i*(k-i)*p);
	}
	cout<<ans<<endl;
	return 0;
}

