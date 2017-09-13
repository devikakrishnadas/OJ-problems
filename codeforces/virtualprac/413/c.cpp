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
	vi bc(100023,300000);
	vi bd(100023,300000);
	int n,c,d;
	cin>>n>>c>>d;
	int b,p;
	char x;
	for(int i=0;i<n;i++)
	{
		cin>>b>>p>>x;
		if(x=='C')
		{
			bc[b]=min(bc[b],p);
		}
		else
		{
			bd[b]=min(bd[b],p);
		}
	}
	int j=100000;
	int ans=0;
	int i=0;
	while(j>=0 && i<=100000)
	{
		if(bc[i]+bc[j]<=c && i!=j)
		{
			ans=max(ans,i+j);
			cout<<"r1"<<endl;
			i++;
		}
		else if(bc[i]<=c && bd[j]<=d)
		{
			cout<<"r2"<<endl;
			ans=max(ans,i+j);
			i++;
		}
		else if(bd[i]<=c && bc[j]<=c)
		{
			cout<<"r3"<<endl;
			ans=max(ans,i+j);
			i++;
		}
		else if(bd[i]+bd[j]<=d && i!=j)
		{
			cout<<"r4"<<endl;
			ans=max(ans,i+j);
			i++;
		}
		else
		{
			cout<<"r5"<<endl;
			//cout<<j<<endl;
			j--;
		}
	}
	cout<<ans<<endl;
	return 0;
}

