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
	//map<int,int>A;
	int n,m;
	cin>>n>>m;
	vi B(n+1);
	vector< vi >G(100203),switches(m+1);
	for(int i=1;i<=n;i++)
	{
		cin>>B[i];
	}
	int k,x,y;
	//cin>>k>>x>>y;
	for(int i=0;i<m;i++)
	{
		cin>>k;
		for(int j=0;j<k;j++)
		{
			cin>>x;
			G[x].pb(i+1);
			switches[i+1].pb(x);
		}
	}
//	cout<<"r1"<<endl;
	vector< vector<pair<int,int> > >A(100023);
	int col[100023]={0};
	for(int i=1;i<=n;i++)
	{
		A[G[i][0]].pb(mp(G[i][1],B[i]));
		A[G[i][1]].pb(mp(G[i][0],B[i]));
		
	}
	int a=1;
	queue<int>q;
	for(int i=1;i<=m;i++)
	{
		if(!col[i])
		{
			a=i;
			q.push(i);
			col[i]=1;
			while(!q.empty())
			{
				a=q.front();
				for(int j=0;j<A[a].size();j++)
				{
					if(!col[A[a][j].first])
						q.push(A[a][j].first);
					if(A[a][j].second)
					{
						if(col[A[a][j].first]!=col[a] && col[A[a][j].first]!=0)
						{
							cout<<"NO"<<endl;
							return 0;
						}
						col[A[a][j].first]=col[a];
					}
					else
					{
						if(col[A[a][j].first]==col[a])
						{
							cout<<"NO"<<endl;
							return 0;
						}
						if(col[a]==1)
						{
							col[A[a][j].first]=2;
						}
						else col[A[a][j].first]=1;
					}
					
				}
				q.pop();
			}
		}
	}
	cout<<"YES"<<endl;
	return 0;
}
