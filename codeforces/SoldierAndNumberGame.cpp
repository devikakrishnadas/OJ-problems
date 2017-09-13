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

vi pr;

void sieve(vi &ans)
{
	for(int i=2;i<=5000000;i++)
	{
		if(ans[i])
		{
			for(int j=2;i*j<=5000000;j++)
			{
				ans[i*j]=0;
			}
			pr.pb(i);
		}
	}
}

void findprimediv(vi &ans)
{
	for(int i=4;i<=5000000;i++)
	{
		if(ans[i]) continue;
		int t=i;
		for(int j=0;pr[j]*pr[j]<=i;j++)
		{
			if(t%pr[j]==0)
			{
				ans[i]=ans[(t/pr[j])]+1;
				break;
			}
		}
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	vi ans(5000000,1);
	sieve(ans);
	findprimediv(ans);
	int t;
	cin>>t;
	for(int i=1;i<=5000000;i++)
	{
		ans[i]+=ans[i-1];
	}
	while(t--)
	{
		int a,b;
		cin>>a>>b;
		cout<<ans[a]-ans[b]<<endl;
	}
	return 0;
}

