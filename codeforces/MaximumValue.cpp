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

vi b(4000005,0);
int main()
{
	
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin>>n;
	vi a;
	int ma=0,x;
	int tt=0;
	for(int i=0;i<n;i++)
	{
		cin>>x;
		if(!b[x]) a.pb(x);
		b[x]=1;
		ma=max(x,ma);
		//cout<<i<<endl;
	}
	//cout<<"r1"<<endl;
	sort(all(a));
	int val=0;
	//cout<<a.size()<<endl;
	//cout<<"r2"<<endl;
	for(int i=0;i<=2*ma;i++)
	{
		if(b[i])
		{
			b[i]=val;
			val=i;
		}
		else
		b[i]=val;
	}
	//cout<<"r3"<<endl;
	ll ans=0;
	for(int i=0;i<a.size();i++)
	{
		for(int j=2;a[i]*j<=2*ma;j++)
		{
			/*if((b[a[i]*j])%a[i]>49990 && tt==13 && ans>49990)
				cout<<(b[a[i]*j])<<" "<<a[i]<<" "<<"="<<" "<<((ll)((b[a[i]*j])))%a[i]<<endl;*/
			ans=max(ans,((ll)((b[a[i]*j])))%a[i]);
		}
	}
	
	cout<<ans<<endl;
	return 0;
}
