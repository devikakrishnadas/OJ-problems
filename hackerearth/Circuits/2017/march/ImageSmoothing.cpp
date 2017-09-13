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
	int n,m;
	cin>>n>>m;
	vector< vi >A(2*m+1);
	int x;
	for(int i=0;i<2*m+1;i++)
	{
		for(int j=0;j<2*m+1)
		{
			cin>>x;
			A[i].pb(x);
		}
	}
	vector< vi >ans(2*m+1),G(n),GNew(n);
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cin>>x;
			G[i].pb(x);
		}
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			x=0;
			for(int p=0;p<2*m+1;p++)
			{
				for(int q=0;q<2*m+1;q++)
				{
					x+=G[i+p][j+q]*A[p][q];
					
				}
			}
			GNew.pb(x);
		}
	}
	return 0;
}

