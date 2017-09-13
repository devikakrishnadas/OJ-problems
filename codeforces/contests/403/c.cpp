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
	std::ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin>>n;
	int x,y;
	vector < vi >A(n+1);
	
	for(int i=0;i<n-1;i++)
	{
		cin>>x>>y;
		A[y].pb(x);
		A[x].pb(y);
	}
	queue<int>q;
	vi col(n+1,-1);
	int a;
//	x=2;
	q.push(x);
	col[x]=1;
	a=x;
	int ans=0;
	int gp=-1;
	while(!q.empty())
	{
		a=q.front();
//		set<int>B;
		vi tc(n+1,0);
		tc[col[a]]=1;
		for(int i=0;i<A[a].size();i++)
		{
			if(col[A[a][i]]!=-1)
				tc[col[A[a][i]]]=1;
			if(col[A[a][i]]==-1)
				q.push(A[a][i]);
		}
		int k=1;
		for(int i=0;i<A[a].size();i++)
		{
			if(col[A[a][i]]==-1)
			{
				while(tc[k]) k++;
				tc[k]=1;
				col[A[a][i]]=k;
			}
		}
		ans=max(ans,k);
		q.pop();
		gp=a;
	}
	cout<<ans<<endl;
	for(int i=1;i<=n;i++)
	{
		cout<<col[i]<<" ";
	}
	cout<<endl;
	return 0;
}

