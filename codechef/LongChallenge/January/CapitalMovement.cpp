#include<bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define vc vector<char>
#define vll vector<ll>
#define pb push_back
#define sf scanf
#define pf printf
#define mp make_pair
#define all(V) V.begin,V.end

using namespace std;

int main()
{
	int t,n;
	cin>>t;
	while(t--)
	{
		cin>>n;
		vi A[100025];
		vector<pair<int,int> >p;
		int z;
		for(int i=1;i<=n;i++)
		{
			cin>>z;
			p.pb(mp(z,i));	
		}
		int x,y;
		for(int i=0;i<n-1;i++)
		{
			cin>>x>>y;
			A[x].pb(y);
			A[y].pb(x);
		}
		sort(p.begin(),p.end());
		reverse(p.begin(),p.end());
		for(int i=1;i<=n;i++)
		{
			int k=0;
			a:for(int j=0;j<A[i].size();j++)
			{
				if(A[i][j]==p[k].second || p[k].second==i)
				{
					k++;
					goto a;
				}
			}
			cout<<p[k].second;
			if(i!=n) cout<<" ";
			else cout<<endl;
		}
	}
	return 0;
}

