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

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin>>t;
	while(t--)
	{
		
		int n,k;
		cin>>n>>k;
		vector< vi >A(n);
		int cnt[100023]={0},cnti[100023]={0};
		for(int i=0;i<n;i++)
		{
			int p;
			cin>>p;
			for(int j=0;j<p;j++)
			{
				int x;
				cin>>x;
				A[i].pb(x);
				if(cnt[x]==0)
				{
					cnti[i]++;
				}
				cnt[x]++;
			}
		}
		bool some=0;
		bool sad=0;
		for(int i=1;i<=k;i++)
		{
			if(!cnt[i])
			{
				sad=1;
				break;
			}
		}
		if(sad)
		{
			cout<<"sad"<<endl;
		}
		else
		{
			for(int i=0;i<n;i++)
			{
				if(cnti[i]==0)
				{
					some=1;
					break;
				}
			}
			if(some)
				cout<<"some"<<endl;
			else
				cout<<"all"<<endl;
		}
	}
	
	return 0;
}

